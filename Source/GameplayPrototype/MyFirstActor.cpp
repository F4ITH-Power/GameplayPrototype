#include "MyFirstActor.h"

AMyFirstActor::AMyFirstActor()
{
	PrimaryActorTick.bCanEverTick = false;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	RootComponent = StaticMesh;
	Health = 100.f;
	bIsDead = false;
}

void AMyFirstActor::BeginPlay()
{
	Super::BeginPlay();
}
void AMyFirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyFirstActor::TakeDamage(float Damage)
{
	if (bIsDead)
	{
		return;
	}

	Health -= Damage;

	UE_LOG(LogTemp, Warning, TEXT("Damage taken: %f | Health: %f"), Damage, Health);

	if (Health <= 0.f)
	{
		bIsDead = true;
		HandleDeath();
	}
}

void AMyFirstActor::HandleDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("Actor died"));

	StaticMesh->SetVisibility(false);

	GetWorldTimerManager().SetTimer(DestroyTimerHandle,this,&AMyFirstActor::FinishDestruction,2.f,false);
	OnDeath();
}

void AMyFirstActor::FinishDestruction()
{
	Destroy();
}

