// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize();

public:
	UMainMenu(const FObjectInitializer& ObjectInitializer);

	void SetServerList(TArray<FString> ServerNames);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UPanelWidget* ServerList;

	void SelectIndex(uint32 Index);

private:
	TSubclassOf<class UUserWidget> ServerRowClass;

	/// Functions
	UFUNCTION(BlueprintCallable)
	void HostServer();

	UFUNCTION(BlueprintCallable)
	void JoinServer();

	UFUNCTION(BlueprintCallable)
	void QuitPressed();
	/// *******

	TOptional<uint32> SelectedIndex;
};
