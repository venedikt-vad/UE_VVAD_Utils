#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#include "Components/SceneComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/HitResult.h" 

#include "VVAD_UtilsBPLib.generated.h"

UCLASS()
class VVAD_UTILS_API UVVAD_UtilsBPLib : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public:
    
    //String

    UFUNCTION(BlueprintPure, Category = "Math|String")
    static bool IsUpper(const FString& InString);

    UFUNCTION(BlueprintPure, Category = "Math|String")
    static bool IsLower(const FString& InString);

    UFUNCTION(BlueprintCallable, Category = "Math|String", meta = (CompactNodeTitle = "+=", DisplayName = "(string) +=",  KeyWords = "string append"))
    static void AppendSet(UPARAM(ref) FString& Variable, const FString& add);


    //Transform
    
    //Gets component WorldLocation and ForwardVector
    UFUNCTION(BlueprintPure, Category = "Math|Transform", meta = (DisplayName = "Pos & Dir (component)"))
    static void ComponentPositionAndDirection( const USceneComponent* Component, FVector& Position, FVector& Direction );

    //Resets scale to 1. Keeps location and rotation unchanged
    UFUNCTION(BlueprintPure, Category = "Math|Transform", meta = (CompactNodeTitle = "Reset Scale"))
    static FTransform TransformResetScale(const FTransform transform);

    UFUNCTION(BlueprintPure, Category = "Math|Transform", meta = (DisplayName = "Pos & Dir"))
    static void TransformToLocationAndForwardDirection(const FTransform transform, FVector& Position, FVector& Direction);

    //Gets closest actor
    UFUNCTION(BlueprintPure, Category = "Math|Transform")
    static AActor* GetClosest(const TArray<AActor*> actors, FVector loc);

    //Trace
    
    //Gets the trace hit location, or if no hit: trace end location
    UFUNCTION(BlueprintPure, Category = "Math|Trace")
    static FVector GetTracePoint(const FHitResult hit);

    //Gets closest hit
    UFUNCTION(BlueprintPure, Category = "Math|Trace")
    static FHitResult GetClosestHit(const TArray<FHitResult> hits);

    //Useful for settng up trases. Start = ComponentLocation, End = ComponentForward * Distance + ComponentLocation
    UFUNCTION(BlueprintPure, Category = "Math|Trace")
    static void ComponentToTraceStartEnd(const USceneComponent* Component, const float distance, FVector& Start, FVector& End);
    
    //Useful for settng up trases. Start = position, End = Direction * Distance + position
    UFUNCTION(BlueprintPure, Category = "Math|Trace")
    static void PositionAndDirectionToTraceStartEnd(const FVector Pos, const FVector Dir, const float Dist, FVector& Start, FVector& End);

    UFUNCTION(BlueprintCallable, Category = "Math|Trace", meta = (DefaultToSelf = "Actor"))
    static FHitResult AddActorOffsetWithCollision(AActor* Actor, bool bLocalOffset, FVector DeltaLocation, int32 CollisionIterations);

    //Float

    UFUNCTION(BlueprintPure, Category = "Math|Float", meta = ( DisplayName = "(float) *-1", KeyWords = ""))
    static float NegateFloat(const float In);
    
    UFUNCTION(BlueprintPure, Category = "Math|Float", meta = (CompactNodeTitle = "1 - X", DisplayName = "(float) 1-x", KeyWords = ""))
    static float OneMinusX(const float X);

    //Returns 1 if true, -1 if false
    UFUNCTION(BlueprintPure, Category = "Math|Float", meta = (CompactNodeTitle = "? 1 : -1", DisplayName = "(float) True+False-", KeyWords = "True+False-"))
    static float TruePositiveFalseNegative(const bool In);

    UFUNCTION(BlueprintPure, Category = "Math|Float", meta = (CompactNodeTitle = "-1", DisplayName = "(float) -1", KeyWords = ""))
    static float FloatMinusOne(const float In);

    UFUNCTION(BlueprintPure, Category = "Math|Float", meta = (CompactNodeTitle = "+1", DisplayName = "(float) +1", KeyWords = ""))
    static float FloatPlusOne(const float In);


    UFUNCTION(BlueprintCallable, Category = "Math|Float", meta = (CompactNodeTitle = "+=", DisplayName = "(float) +=", KeyWords = "float add"))
    static void AddAssignF(UPARAM(ref) float& Variable, const float add);

    UFUNCTION(BlueprintCallable, Category = "Math|Float", meta = (CompactNodeTitle = "-=", DisplayName = "(float) -= ", KeyWords = "float subtract"))
    static void SubtAssignF(UPARAM(ref) float& Variable, const float subtract);

    UFUNCTION(BlueprintCallable, Category = "Math|Float", meta = ( DisplayName = "(float) /="))
    static void DivideAssignF(UPARAM(ref) float& Variable, const float divider);

    UFUNCTION(BlueprintCallable, Category = "Math|Float", meta = (DisplayName = "(float) *="))
    static void MultiplyAssignF(UPARAM(ref) float& Variable, const float multiplier);
    
    UFUNCTION(BlueprintCallable, Category = "Math|Float", meta = (CompactNodeTitle = "%=", DisplayName = "(float) %=", KeyWords = "float modulo"))
    static void ModuloAssignF(UPARAM(ref) float& Variable, const float modulo);

    //Integer

    UFUNCTION(BlueprintPure, Category = "Math|Integer", meta = (DisplayName = "(Integer) *-1"))
    static int32 NegateInt(const int32 In);
    
    UFUNCTION(BlueprintPure, Category = "Math|Integer", meta = (CompactNodeTitle = "-1", DisplayName = "(Integer) -1", KeyWords = ""))
    static int32 IntMinusOne(const int32 In);

    UFUNCTION(BlueprintPure, Category = "Math|Integer", meta = (CompactNodeTitle = "+1", DisplayName = "(Integer) +1", KeyWords = ""))
    static int32 IntPlusOne(const int32 In);

    UFUNCTION(BlueprintCallable, Category = "Math|Integer", meta = (CompactNodeTitle = "+=", DisplayName = "(Integer) +=", KeyWords = "Integer add"))
    static void AddAssignInt(UPARAM(ref) int32& Variable, const int32 add);

    UFUNCTION(BlueprintCallable, Category = "Math|Integer", meta = (CompactNodeTitle = "-=", DisplayName = "(Integer) -= ", KeyWords = "Integer subtract"))
    static void SubtAssignInt(UPARAM(ref) int32& Variable, const int32 subtract);

    UFUNCTION(BlueprintCallable, Category = "Math|Integer", meta = (CompactNodeTitle = "/=", DisplayName = "(Integer) /=", KeyWords = "Integer divide"))
    static void DivideAssignInt(UPARAM(ref) int32& Variable, const int32 divider);

    UFUNCTION(BlueprintCallable, Category = "Math|Integer", meta = (CompactNodeTitle = "*=", DisplayName = "(Integer) *=", KeyWords = "Integer multiply"))
    static void MultiplyAssignInt(UPARAM(ref) int32& Variable, const int32 multiplier);

    UFUNCTION(BlueprintCallable, Category = "Math|Integer", meta = (CompactNodeTitle = "%=", DisplayName = "(Integer) %=", KeyWords = "Integer modulo"))
    static void ModuloAssignInt(UPARAM(ref) int32& Variable, const int32 modulo);
};
