// Fill out your copyright notice in the Description page of Project Settings.


#include "Tutorial/TutorialGameMode.h"

ATutorialGameMode::ATutorialGameMode() {
	ConstructorHelpers::FClassFinder<APawn> MainCharacter(TEXT("/Game/Character/BP/BP_PlayerCharacter"));

	DefaultPawnClass = MainCharacter.Class;

}