// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectGameplayTags.h"

namespace ProjectGameplayTags
{
	/** Input Tags **/
	// ������� extern���� ������ InputTag_T�� �������� FGameplayTag�� �����ϰ�, 
	// ���������� UGameplayTagsManager::Get().RequestGameplayTag("InputTag.Move") �� ȣ���� �±׸� �ʱ�ȭ�� �ݴϴ�.

	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move")
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look")
}