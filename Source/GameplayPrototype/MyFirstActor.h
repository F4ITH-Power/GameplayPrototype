// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyFirstActor.generated.h"

UCLASS()
class GAMEPLAYPROTOTYPE_API AMyFirstActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyFirstActor();
	
	void TakeDamage(float Damage);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* StaticMesh;
	
	virtual void OnDeath();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:
	// === Состояние ===
	bool bIsDead;
	float Health;
	// === Таймер ===
	FTimerHandle DestroyTimerHandle;
	
	void FinishDestruction();
};
