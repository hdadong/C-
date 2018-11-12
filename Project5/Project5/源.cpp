
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
	
	//��ʼһ������ʶ��
	const char * params = "engine_type = local, asr_res_path = ****, sample_rate = ****, grm_build_path = ****, local_grammar = ****, result_type = json, result_encoding = UTF-8";
	ret = 0;
	const char* sessionID = QISRSessionBegin(NULL, params, &ret);//�ɹ������ַ�����ʽ��ID,
	if (MSP_SUCCESS != ret)
	{
		printf("QISRSessionBegin failed, error code is: %d", ret);
	}
	/////////////////////////////////////////////
	//д�뱾��ʶ�����Ƶ
	char audio_data[5120] = { '\0' };
	unsigned int audio_len = 0;
	int audio_status = 2;
	int ep_status = 0;
	int rec_status = 0;
	ret = 0;
	while (MSP_AUDIO_SAMPLE_LAST != audio_status)
	{
		// ��ȡ��Ƶ��������audio_data �У�������Ƶ����audio_len����Ƶ״̬audio_status��
		ret = QISRAudioWrite(sessionID, audio_data, audio_len, audio_status, &ep_status, &rec_status);
		if (MSP_SUCCESS  != ret)
		{
			printf("QISRAudioWrite failed, error code is: %d", ret);
			break;
		}
		else if (MSP_EP_AFTER_SPEECH == ep_status) // ��⵽��Ƶ��˵㣬ֹͣд����Ƶ
		{
			printf("end point of speech has been detected!");
			break;
		}
		// �����ʵʱ�ɼ���Ƶ������ʡ�Դ˲�����5KB ��С��16KPCM ������ʱ����160 ����
		Sleep(160);
	}
	

	/////////////////////////
	//����ִ�гɹ�����ʶ����ʱ�����ؽ���ַ���ָ�룻�������(ʧ�ܻ��޽��)����NULL�� 


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
			// �û������������ķ�ʽ����ʶ����
			strcat_s(rslt_str, rec_result);
			continue;
		}
		// sleep һ�º��б�Ҫ����ֹMSC ���޻����ʶ����ʱ�˷�CPU ��Դ
		Sleep(200);
	}
	////////////////////////////////////
	ret = QISRSessionEnd(sessionID, "normal end");
	if (MSP_SUCCESS != ret)
	{
		printf("QISRSessionEnd failed, error code is: %d", ret);
	}

	

	//���ӿں�MSPLogin���ʹ�á�ȷ�������ӿڵ��ý���֮�����MSPLogout������������Ԥ�ڡ�
	ret = MSPLogout();
	if (MSP_SUCCESS != ret)
	{
		printf("MSPLogout failed, error code is: %d", ret);
	}


	

	getchar();

	return 0;
}
