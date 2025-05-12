// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	// �Ϻ� VFX�� �ٴڿ� ��Į�� �����ϴµ�, ĳ���� �޽ð� �ƴ� �ٴڿ��� ������ ��ġ���� �ϱ�����
	GetMesh()->bReceivesDecals = false;
}
