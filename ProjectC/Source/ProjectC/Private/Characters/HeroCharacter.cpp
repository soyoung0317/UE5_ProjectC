// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/HeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ProjectDebugHelper.h"

AHeroCharacter::AHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f); // ĸ��������Ʈ �ʱ�ȭ 

	// ��Ʈ�ѷ� ȸ����뿩�� ���� => false�̹Ƿ�, ���콺�� ī�޶� �������� ĳ���� ��ü�� �ٷ� ���� �������� �ʴ´�. 
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// ī�޶� ��(Spring Arm)���� & ���� 
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent()); // ī�޶� ��Ʈ(ĸ��)�� ����
	CameraBoom->TargetArmLength = 200.f; // �Ÿ�����
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f); // ��ġ ������
	CameraBoom->bUsePawnControlRotation = true; // ȸ�� ���󰡱� - �÷��̾ ���콺�� ī�޶� ������ �������ϵ� �Բ� ȸ���Ѵ�. 

	// ���� ī�޶� ������Ʈ ���� & ����
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // �������� ���� ����
	FollowCamera->bUsePawnControlRotation = false; // ī�޶� ��ü ȸ�� - ���������� ȸ���� �Ǵٽ� ��������ʵ����� = �̹� ȸ���� ó���ϹǷ� �ߺ�����

	// ĳ���� �̵� ����
	GetCharacterMovement()->bOrientRotationToMovement = true; // �̵����⿡ ���� ĳ���Ͱ� �ڵ����� ���� ������. 
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f; // ����(�극��ũ) ���� �߰� 
}

void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	Debug::Print(TEXT("Working"));
}
