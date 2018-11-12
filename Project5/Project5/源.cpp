
#include"msp_cmn.h"
#include"msp_errors.h"
#include<stdio.h>
#include<Windows.h>
#include"qisr.h"
#include"qise.h"
#include"qtts.h"
#include"msp_types.h"
#ifdef _WIN64
#pragma comment(lib,"D:/C++/Project5/libs/msc_x64.lib")
#else 
#pragma comment(lib,"D:/C++/Project5/libs/msc.lib")
#endif

int main()
{
	const char* usr = NULL;
	const char* pwd = NULL;
	const char* lgi_param = "appid = ********";
	int ret = MSPLogin(usr, pwd, lgi_param);
	if (MSP_SUCCESS !=ret)
	{
		printf("MSPLogin failed, error code is: %d", ret);
	}
	
	//开始一次语音识别
	const char * params = "engine_type = local, asr_res_path = ****, sample_rate = ****, grm_build_path = ****, local_grammar = ****, result_type = json, result_encoding = UTF-8";
	ret = 0;
	const char* sessionID = QISRSessionBegin(NULL, params, &ret);//成功返回字符串格式的ID,
	if (MSP_SUCCESS != ret)
	{
		printf("QISRSessionBegin failed, error code is: %d", ret);
	}
	/////////////////////////////////////////////
	//写入本次识别的音频
	char audio_data[5120] = { '\0' };
	unsigned int audio_len = 0;
	int audio_status = 2;
	int ep_status = 0;
	int rec_status = 0;
	ret = 0;
	while (MSP_AUDIO_SAMPLE_LAST != audio_status)
	{
		// 读取音频到缓冲区audio_data 中，设置音频长度audio_len，音频状态audio_status。
		ret = QISRAudioWrite(sessionID, audio_data, audio_len, audio_status, &ep_status, &rec_status);
		if (MSP_SUCCESS  != ret)
		{
			printf("QISRAudioWrite failed, error code is: %d", ret);
			break;
		}
		else if (MSP_EP_AFTER_SPEECH == ep_status) // 检测到音频后端点，停止写入音频
		{
			printf("end point of speech has been detected!");
			break;
		}
		// 如果是实时采集音频，可以省略此操作。5KB 大小的16KPCM 持续的时间是160 毫秒
		Sleep(160);
	}
	

	/////////////////////////
	//函数执行成功且有识别结果时，返回结果字符串指针；其他情况(失败或无结果)返回NULL。 


	char rslt_str[2048] = { '\0' };
	const char* rec_result = NULL;
	int rslt_status = 0;
	ret = 0;
	while (MSP_REC_STATUS_COMPLETE != rslt_status)
	{
		rec_result = QISRGetResult(sessionID, &rslt_status, 5000, &ret);
		if (MSP_SUCCESS != ret)
		{
			printf("QISRGetResult failed, error code is: %d", ret);
			break;
		}
		if (NULL != rec_result)
		{
			// 用户可以用其他的方式保存识别结果
			strcat_s(rslt_str, rec_result);
			continue;
		}
		// sleep 一下很有必要，防止MSC 端无缓存的识别结果时浪费CPU 资源
		Sleep(200);
	}
	////////////////////////////////////
	ret = QISRSessionEnd(sessionID, "normal end");
	if (MSP_SUCCESS != ret)
	{
		printf("QISRSessionEnd failed, error code is: %d", ret);
	}

	

	//本接口和MSPLogin配合使用。确保其他接口调用结束之后调用MSPLogout，否则结果不可预期。
	ret = MSPLogout();
	if (MSP_SUCCESS != ret)
	{
		printf("MSPLogout failed, error code is: %d", ret);
	}


	

	getchar();

	return 0;
}
