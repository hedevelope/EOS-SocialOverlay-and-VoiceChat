// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EOS_GameInstance.generated.h"


 
UCLASS()
class VM_TEST_API UEOS_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	/**
 * 
	virtual void Init() override;
	virtual void Shutdown() override;

	void InitVivox();
	void Login();
	void JoinChannel();

	IClient* VivoxVoiceClient;
	AccountId LoggedUserId;
*/
};
