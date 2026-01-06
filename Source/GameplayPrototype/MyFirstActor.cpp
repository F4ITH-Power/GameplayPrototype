// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstActor.h"

// Sets default values
AMyFirstActor::AMyFirstActor()
{
	PrimaryActorTick.bCanEverTick = false; // Tick пока не нужен
	Health = 100.f; // начальное здоровье

}

void AMyFirstActor::TakeDamage(float Damage)
{
	Health -= Damage;

	UE_LOG(LogTemp, Warning, TEXT("TakeDamage called. Health now: %f"), Health);

	if (Health <= 0.f)
	{
		Destroy(); // удаляем Actor из мира
	}
}
// Called when the game starts or when spawned
void AMyFirstActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

