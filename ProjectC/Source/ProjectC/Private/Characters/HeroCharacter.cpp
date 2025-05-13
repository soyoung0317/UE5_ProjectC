// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/HeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/Input/WarriorInputComponent.h"
#include "ProjectGameplayTags.h"

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

void AHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Forgot to assign a valid data asset as input config"));

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UWarriorInputComponent* WarriorInputComponent = CastChecked<UWarriorInputComponent>(PlayerInputComponent);

	// Move ����
	WarriorInputComponent->BindNativeInputAction(InputConfigDataAsset, ProjectGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	WarriorInputComponent->BindNativeInputAction(InputConfigDataAsset, ProjectGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
}

void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	Debug::Print(TEXT("Debug Working"));
}

void AHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if(MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (LookAxisVector.X != 0.f)
		AddControllerYawInput(LookAxisVector.X);

	if (LookAxisVector.Y != 0.f)
		AddControllerPitchInput(LookAxisVector.Y);


}
