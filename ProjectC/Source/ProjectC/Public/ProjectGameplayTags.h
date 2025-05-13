// Fill out your copyright notice in the Description page of Project Settings.
// ������Ʈ ���ݿ��� ����� InputTag�� ����,�����Ѵ�. 
#pragma once

#include "NativeGameplayTags.h"

namespace ProjectGameplayTags
{
	/** Input Tags **/
	// PROJECTC_API :  ���� ������Ʈ�� ���(�÷�����, ���� ��� ��)���� �и��Ǿ� ���� ��,
	// �� �±� ������ �ٸ� ��⿡���� �� �� �ֵ��� __declspec(dllexport/dllimport) �÷��׸� �ٿ��ִ� ��ũ���Դϴ�.
    // ���� ���� ��DLL ��� �ۿ����� ����(link)�� �ּ��䡱 ��� ��

	PROJECTC_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move) // �ܺο� ����� ���������� ����ڴٰ� �����Ϸ����� �˷���
	PROJECTC_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look)
}