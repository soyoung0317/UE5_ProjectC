// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/HeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ProjectDebugHelper.h"

AHeroCharacter::AHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f); // 캡슐컴포넌트 초기화 

	// 컨트롤러 회전사용여부 설정 => false이므로, 마우스로 카메라를 움직여도 캐릭터 몸체는 바로 따라 움직이지 않는다. 
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// 카메라 붐(Spring Arm)생성 & 설정 
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent()); // 카메라를 루트(캡슐)에 부착
	CameraBoom->TargetArmLength = 200.f; // 거리조정
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f); // 위치 오프셋
	CameraBoom->bUsePawnControlRotation = true; // 회전 따라가기 - 플레이어가 마우스로 카메라를 돌리면 스프링암도 함께 회전한다. 

	// 실제 카메라 컴포넌트 생성 & 부착
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // 스프링암 끝에 고정
	FollowCamera->bUsePawnControlRotation = false; // 카메라 자체 회전 - 스프링암의 회전을 또다시 적용받지않도록함 = 이미 회전을 처리하므로 중복방지

	// 캐릭터 이동 설정
	GetCharacterMovement()->bOrientRotationToMovement = true; // 이동방향에 맞춰 캐릭터가 자동으로 몸을 돌린다. 
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f; // 감속(브레이크) 세기 추가 
}

void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	Debug::Print(TEXT("Working"));
}
