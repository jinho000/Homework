#include "LoginResultPacketHandler.h"	
#include <Kismet/GameplayStatics.h>
#include "../../Global/CGameInstance.h"
#include "../../Login/CLoginUI.h"


void LoginResultPacketHandler::Start()
{
	UE_LOG(LogTemp, Log, TEXT("LoginResultPacketHandler"));

	// �����κ��� �α�����Ŷ ���������� Ȯ��
	if (ELoginResultCode::OK == m_packet->LoginResultCode)
	{
		UE_LOG(LogTemp, Log, TEXT("Recv Login Result Packet"));
		UE_LOG(LogTemp, Log, TEXT("Loading User Character List"));
		m_pGameInst->LoginProcess = true;

		// UDP��Ʈ �޾ƿ���
		m_pGameInst->SetUDPEndPoint(m_packet->UDPPort);

		return;
	}


	// �α��� ����
	m_pGameInst->LoginProcess = false;

	// ���̵� ����
	if (ELoginResultCode::ID_ERROR == m_packet->LoginResultCode)
	{
		UE_LOG(LogTemp, Log, TEXT("ID Fail"));
		m_pGameInst->LoginUI->LoginStatus = TEXT("ID Fail");
		return;
	}

	// ��й�ȣ�� ��ġ���� ����
	if (ELoginResultCode::PW_ERROR == m_packet->LoginResultCode)
	{
		UE_LOG(LogTemp, Log, TEXT("Password Fail"));
		m_pGameInst->LoginUI->LoginStatus = TEXT("Password Fail");
		return;
	}
}

