// Fill out your copyright notice in the Description page of Project Settings.

#include "EOS_GameInstance.h"
/**
#define VIVOX_VOICE_SERVER TEXT("https://unity.vivox.com/appconfig/18966-unrea-80514-udash")
#define VIVOX_VOICE_DOMAIN TEXT("mtu1xp.vivox.com")
#define VIVOX_VOICE_ISSUER TEXT("18966-unrea-80514-udash")
#define VIVOX_VOICE_KEY TEXT("eM9eWrhz6SwCtZiHpAiXFiUruOShL4VbS")

 

void UEOS_GameInstance::Init()
{
	Super::Init();
	InitVivox();
}

void UEOS_GameInstance::Shutdown()
{
	Super::Shutdown();
	VivoxVoiceClient->Uninitialize();
}

void UEOS_GameInstance::InitVivox()
{
	VivoxVoiceClient = &static_cast<FVivoxCoreModule*>(&FModuleManager::Get().LoadModuleChecked(TEXT("VivoxCore")))->VoiceClient();
	VivoxVoiceClient->Initialize();
	Login();
}

void UEOS_GameInstance::Login()
{
	LoggedUserId = AccountId(VIVOX_VOICE_ISSUER, "PlayerId", VIVOX_VOICE_DOMAIN);
	ILoginSession& MyLoginSession(VivoxVoiceClient->GetLoginSession(LoggedUserId));

	FTimespan TokenExpiration = FTimespan::FromSeconds(90);
	FString LoginToken = MyLoginSession.GetLoginToken(VIVOX_VOICE_KEY, TokenExpiration);

	ILoginSession::FOnBeginLoginCompletedDelegate OnBeginLoginCompleted;
	OnBeginLoginCompleted.BindLambda([this, &MyLoginSession](VivoxCoreError Error)
	{
		UE_LOG(LogTemp, Log, TEXT("Logged into Vivox! :D"));
		JoinChannel();
	});

	MyLoginSession.BeginLogin(VIVOX_VOICE_SERVER, LoginToken, OnBeginLoginCompleted);
}

void UEOS_GameInstance::JoinChannel()
{
	ILoginSession& MyLoginSession = VivoxVoiceClient->GetLoginSession(LoggedUserId);
	ChannelId Channel = ChannelId(VIVOX_VOICE_ISSUER, "ChannelId", VIVOX_VOICE_DOMAIN, ChannelType::NonPositional);
	IChannelSession& ChannelSession = MyLoginSession.GetChannelSession(Channel);

	FTimespan TokenExpiration = FTimespan::FromSeconds(90);
	FString JoinToken = ChannelSession.GetConnectToken(VIVOX_VOICE_KEY, TokenExpiration);

	ChannelSession.BeginConnect(true, false ,true, JoinToken, NULL);
}
*/