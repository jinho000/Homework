// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientPlayCharacter.h"
#include <GameFramework/PlayerInput.h>
#include <Kismet/GameplayStatics.h>
#include "../../UnrealClient.h"
#include "../../Global/CGameInstance.h"
#include "../../Packets/ClientPackets/Packets.h"
#include "../../Packets/ClientPackets/ServerSerializer.h"
#include "../../Packets/ClientPackets/Packets.h"
#include "../../Play/PlayGameMode.h"

AClientPlayCharacter::AClientPlayCharacter()
	: AClientCharacter()
	, m_MoveVector()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AClientPlayCharacter::BeginPlay()
{
	Super::BeginPlay();

	// UDP ������ ����
	// �÷��̾� ���۽ú��� UDP��Ŷ�� �޴´�
	UCGameInstance* gameInst = Cast<UCGameInstance>(GetGameInstance());
	gameInst->StartUDPThread();
	
	//packet.PlayerData.PlayerID = gameInst->GetPlayerID();
	//packet.PlayerData.Dir = GetActorForwardVector();
	//packet.PlayerData.Pos = GetActorLocation();

	//FQuat RotData = GetActorQuat();
	//packet.PlayerData.Rot = FVector4(RotData.X, RotData.Y, RotData.Z, RotData.W);
	//packet.PlayerData.State = static_cast<int>(GetClientAnimInstance()->GetAnimationType());

	//UpdateMsg.Data.ObjectIndex = Inst->ObjectIndex;
	//UpdateMsg.Data.SectionIndex = Inst->SectionIndex;
	//UpdateMsg.Data.ThreadIndex = Inst->ThreadIndex;

	//ServerSerializer sr;
	//packet >> sr;
	//gameInst->SendBytes(sr.GetBuffer());
}

// Called every frame
void AClientPlayCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SendUDPPlayerData();

	//m_pingTime += DeltaTime;

	//// ������ üũ
	//static int accframe = 0;
	//++accframe;

	//// 5�����Ӹ��� ��Ŷ ������
	//if (accframe % 5 == 0)
	//{
	//	accframe = 0;
	//}
}

// Called to bind functionality to input
void AClientPlayCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	static bool bBindingsAdded = false;
	if (!bBindingsAdded)
	{
		bBindingsAdded = true;

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("ClientPlayer_MoveForward", EKeys::W, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("ClientPlayer_MoveForward", EKeys::S, -1.f));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("ClientPlayer_Move", EKeys::W));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("ClientPlayer_Move", EKeys::S));


		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("ClientPlayer_MoveRight", EKeys::D, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("ClientPlayer_MoveRight", EKeys::A, -1.f));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("ClientPlayer_Move", EKeys::D));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("ClientPlayer_Move", EKeys::A));

		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("TestFunc", EKeys::NumPadZero));
		//UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("ClientPlayer_Attack", EKeys::LeftMouseButton));

	}

	// �󸶳� ���������� ���������� ���� ������ ���ϰ� �����ٴ� üũ�ؾ��Ҷ��� �����ϴ�.
	// ���� ���� Ű�� �ԷµǾ����� 
	PlayerInputComponent->BindAxis("DefaultPawn_MoveForward", this, &AClientPlayCharacter::MoveForward);
	PlayerInputComponent->BindAxis("ClientPlayer_MoveRight", this, &AClientPlayCharacter::MoveRight);
	PlayerInputComponent->BindAction("ClientPlayer_Move", EInputEvent::IE_Pressed, this, &AClientPlayCharacter::MoveStart);
	PlayerInputComponent->BindAction("ClientPlayer_Move", EInputEvent::IE_Released, this, &AClientPlayCharacter::MoveEnd);

	//PlayerInputComponent->BindAction("ClientPlayer_Attack", EInputEvent::IE_Released, this, &AClientPlayCharacter::Attack);
	PlayerInputComponent->BindAction("TestFunc", EInputEvent::IE_Released, this, &AClientPlayCharacter::TestFunction);

	FInputModeGameAndUI InputMode;
	GetWorld()->GetFirstPlayerController()->SetInputMode(InputMode);
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
}


void AClientPlayCharacter::MoveRight(float _Rate)
{
	if (0.0f == _Rate)
	{
		return;
	}

	AddControllerYawInput(LookZ(FVector(1.0f, 1.0f, 0.0f).GetSafeNormal() * _Rate, 0.1f));

	AddMovementInput(FVector(1.0f, 1.0f, 0.0f).GetSafeNormal(), _Rate);
	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Move);
}

void AClientPlayCharacter::MoveForward(float _Rate)
{
	if (0.0f == _Rate)
	{
		return;
	}

	AddControllerYawInput(LookZ(FVector(1.0f, -1.0f, 0.0f).GetSafeNormal() * _Rate, 0.1f));
	AddMovementInput(FVector(1.0f, -1.0f, 0.0f).GetSafeNormal(), _Rate);
	
	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Move);
}

void AClientPlayCharacter::MoveStart()
{
	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Move);
}

void AClientPlayCharacter::MoveEnd()
{
	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Idle);
}

void AClientPlayCharacter::Attack()
{
	// ȭ���� �ٶ󺸴°� Ŭ���̾�Ʈ ���Դϴ�.

	// LookZ(FVector(1.0f, -1.0f, 0.0f).GetSafeNormal() * _Rate, 0.1f);

	LookZ(MouseVectorToWorldVector() - GetActorLocation());

	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Attack);
}

void AClientPlayCharacter::SendUDPPlayerData()
{
	UCGameInstance* gameInst = Cast<UCGameInstance>(GetGameInstance());
	PlayerUpdatePacket packet;
	packet.PlayerData.PlayerID = gameInst->GetPlayerID();
	packet.PlayerData.SessionIdx = gameInst->GetSessionIdx();
	packet.PlayerData.PlayerIdx = gameInst->GetPlayerIdx();

	packet.PlayerData.Dir = GetActorForwardVector();
	packet.PlayerData.Pos = GetActorLocation();

	FQuat RotData = GetActorQuat();
	packet.PlayerData.Rot = FVector4(RotData.X, RotData.Y, RotData.Z, RotData.W);
	packet.PlayerData.State = static_cast<int>(GetClientAnimInstance()->GetAnimationType());

	ServerSerializer sr;
	packet >> sr;
	gameInst->SendUDP(sr.GetBuffer());	
}


FVector AClientPlayCharacter::MouseVectorToWorldVector()
{
	//if (false == UDPReady)
	//{
	//	return FVector(TNumericLimits<float>::Max(), TNumericLimits<float>::Max(), TNumericLimits<float>::Max());
	//}

	APlayerController* PC = Cast<APlayerController>(GetController());

	if (nullptr == PC && PC->IsValidLowLevel())
	{
		UE_LOG(ClientLog, Error, TEXT("%S(%u) > nullptr Controller"), __FUNCTION__, __LINE__);
		// ���ѰŴ�. 
		return FVector(TNumericLimits<float>::Max(), TNumericLimits<float>::Max(), TNumericLimits<float>::Max());
	}


	FHitResult TraceHitResult;

	if (false == PC->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult))
	{
		//     ���� ��ǥ�̱� ������
		return FVector(TNumericLimits<float>::Max(), TNumericLimits<float>::Max(), TNumericLimits<float>::Max());
	}

	return TraceHitResult.Location;
}

void AClientPlayCharacter::TestFunction()
{
	SendUDPPlayerData();
}

float PingStartTime = 0.f;
float PingEndTime = 0.f;

void AClientPlayCharacter::PingStart()
{
	PingStartTime = m_pingTime;
}

void AClientPlayCharacter::PingEnd()
{
	// ��Ŷ ���ú� ������

	PingEndTime = m_pingTime;

	//float pingTime = PingEndTime - PingStartTime;
	UE_LOG(LogTemp, Log, TEXT("ping: %f"), PingEndTime - PingStartTime);

	PingStartTime = 0.f;
	PingEndTime = 0.f;
}

