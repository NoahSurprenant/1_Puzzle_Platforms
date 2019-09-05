// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

#include "UObject/ConstructorHelpers.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"

#include "ServerRow.h"

UMainMenu::UMainMenu(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> ServerRowBPClass(TEXT("/Game/MenuSystem/WBP_ServerRow"));
	if (!ensure(ServerRowBPClass.Class != nullptr)) return;

	ServerRowClass = ServerRowBPClass.Class;
}

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	//if (!ensure(HostButton != nullptr)) return false;
	//HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	//if (!ensure(JoinButton != nullptr)) return false;
	//JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	//if (!ensure(JoinMenuBackButton != nullptr)) return false;
	//JoinMenuBackButton->OnClicked.AddDynamic(this, &UMainMenu::OpenMainMenu);

	/*UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return false;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return false;
	HostButton->SetUserFocus(PlayerController);*/

	return true;
}

void UMainMenu::HostServer()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}

void UMainMenu::JoinServer()
{
	if (MenuInterface != nullptr)
	{
		/*const FString& IPAddress = IPAddressField->GetText().ToString();
		MenuInterface->Join(IPAddress);*/
		UWorld* World = this->GetWorld();
		if (!ensure(World != nullptr)) return;

		UServerRow* Row = CreateWidget<UServerRow>(World, ServerRowClass);
		if (!ensure(Row != nullptr)) return;

		ServerList->AddChild(Row);
	}
}

void UMainMenu::QuitPressed()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ConsoleCommand("quit");
}
