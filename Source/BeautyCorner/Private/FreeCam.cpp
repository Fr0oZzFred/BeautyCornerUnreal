#include "FreeCam.h"

AFreeCam::AFreeCam() {
	PrimaryActorTick.bCanEverTick = true;
}

void AFreeCam::BeginPlay() {
	Super::BeginPlay();
    APlayerController* PC = Cast<APlayerController>(GetController());
    PC->SetInputMode(FInputModeGameOnly());
}

void AFreeCam::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AFreeCam::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
    APlayerController* PC = Cast<APlayerController>(GetController());

    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());

    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(InputMapping, 0);

    UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent);

    PEI->BindAction(InputActions->InputMove, ETriggerEvent::Triggered, this, &AFreeCam::Move);
    PEI->BindAction(InputActions->InputMouse, ETriggerEvent::Triggered, this, &AFreeCam::RotateCam);
    PEI->BindAction(InputActions->InputMouseScroll, ETriggerEvent::Triggered, this, &AFreeCam::AddMoveSpeed);
}

void AFreeCam::Move(const FInputActionValue& Value) {
    if (Controller == nullptr) return;
    const FVector MoveValue = Value.Get<FVector>() * MovementSpeed * MovementSpeedMultiplier;
    this->AddActorLocalOffset(MoveValue);
}

void AFreeCam::RotateCam(const FInputActionValue& Value) {
    if (Controller == nullptr) return;
    FQuat nRot = GetActorRotation().Quaternion();
    FVector euler = nRot.Euler();
    FVector2D v = Value.Get<FVector2D>() * CameraSpeed;
    FVector rotation(0.0f,v.Y, v.X);
    euler += rotation;
    nRot = FQuat::MakeFromEuler(euler);


    this->SetActorRotation(nRot);
}

void AFreeCam::AddMoveSpeed(const FInputActionValue& Value) {
    if (Controller == nullptr) return;
    MovementSpeedMultiplier += Value.Get<float>();
    MovementSpeedMultiplier = FMath::Clamp(MovementSpeedMultiplier, 0.1f, 10.0f);
}
