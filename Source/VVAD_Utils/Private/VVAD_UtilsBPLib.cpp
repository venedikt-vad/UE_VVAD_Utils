// MyBlueprintLibrary.cpp
#include "VVAD_UtilsBPLib.h"

bool UVVAD_UtilsBPLib::IsUpper(const FString& InString) {
    for (TCHAR Ch : InString) {
        if (FChar::IsAlpha(Ch)) {
            if (!FChar::IsUpper(Ch)) {
                return false;
            }
        }
    }
    return true;
}

bool UVVAD_UtilsBPLib::IsLower(const FString& InString) {
    for (TCHAR Ch : InString) {
        if (FChar::IsAlpha(Ch)) {
            if (!FChar::IsLower(Ch)) {
                return false;
            }
        }
    }
    return true;
}

void UVVAD_UtilsBPLib::AppendSet(UPARAM(ref)FString& Variable, const FString& add) {
    Variable += add;
    return;
}

void UVVAD_UtilsBPLib::ComponentPositionAndDirection( const USceneComponent* Component, FVector& Position, FVector& Direction ) {
    if (!Component) {
        Position = FVector::ZeroVector;
        Direction = FVector::ForwardVector;
        return;
    }

    Position = Component->GetComponentLocation();
    Direction = Component->GetForwardVector();
}

FTransform UVVAD_UtilsBPLib::TransformResetScale(const FTransform transform) {
    return FTransform(transform.GetRotation(),transform.GetTranslation(), FVector::OneVector);
}

void UVVAD_UtilsBPLib::TransformToLocationAndForwardDirection(const FTransform transform, FVector& Position, FVector& Direction) {
    Position = transform.GetLocation();
    Direction = transform.GetRotation().GetForwardVector();
}

FVector UVVAD_UtilsBPLib::GetTracePoint(const FHitResult hit) {
    if (hit.bBlockingHit) return hit.Location;
    else return hit.TraceEnd;
}

FHitResult UVVAD_UtilsBPLib::GetClosestHit(const TArray<FHitResult> hits) {
    if (hits.IsEmpty()) return FHitResult();
    FHitResult closest = hits[0];
    for (FHitResult h : hits) {
        if (h.Distance < closest.Distance) {
            closest = h;
        }
    }
    return closest;
}

AActor* UVVAD_UtilsBPLib::GetClosest(const TArray<AActor*> actors, FVector loc){
    if (actors.IsEmpty()) return nullptr;
    AActor* closest = actors[0];
    float closest_dist = (closest->GetActorLocation() - loc).Size();
    for (AActor* a : actors) {
        float a_dist = (a->GetActorLocation() - loc).Size();
        if (a_dist < closest_dist) {
            closest = a;
            closest_dist = a_dist;
        }
    }
    return closest;
}

void UVVAD_UtilsBPLib::ComponentToTraceStartEnd(const USceneComponent* Component, const float distance, FVector& Start, FVector& End) {
    if (!Component) {
        Start = FVector::ZeroVector;
        End = FVector::ZeroVector;
        return;
    }

    Start = Component->GetComponentLocation();
    End = Start + (Component->GetForwardVector() * distance);
}

void UVVAD_UtilsBPLib::PositionAndDirectionToTraceStartEnd(const FVector Pos, const FVector Dir, const float Dist, FVector& Start, FVector& End) {
    Start = Pos;
    End = Pos + (Dir * Dist);
}

FHitResult UVVAD_UtilsBPLib::AddActorOffsetWithCollision(AActor* Actor, bool bLocalOffset, FVector DeltaLocation, int32 CollisionIterations) {
    if (!Actor || CollisionIterations <= 0) return FHitResult();

    FVector locBefore = Actor->GetActorLocation();
    FVector movement_vector = DeltaLocation;
    if(bLocalOffset) movement_vector = Actor->GetActorTransform().TransformVector(movement_vector);
    int32 i = CollisionIterations;
    while (!movement_vector.IsNearlyZero()) {
        FHitResult hit;
        Actor->AddActorWorldOffset(movement_vector, true, &hit);

        if (hit.bBlockingHit) {
            movement_vector = (movement_vector - (movement_vector.Normalize() * (hit.Location - locBefore)));
            movement_vector = FVector::VectorPlaneProject(movement_vector, hit.ImpactNormal);
            locBefore = Actor->GetActorLocation();
        } else {
            movement_vector = FVector::ZeroVector;
            return FHitResult();
        }

        i--;
        if (i <= 0) return hit;
    }
    return FHitResult();
}

float UVVAD_UtilsBPLib::NegateFloat(const float In) {
    return In*-1.f;
}

float UVVAD_UtilsBPLib::OneMinusX(const float X) {
    return 1.f-X;
}

float UVVAD_UtilsBPLib::TruePositiveFalseNegative(const bool In) {
    return In ? 1.f : -1.f;
}

float UVVAD_UtilsBPLib::FloatMinusOne(const float In) {
    return In - 1.f;
}

float UVVAD_UtilsBPLib::FloatPlusOne(const float In) {
    return In + 1.f;
}

void UVVAD_UtilsBPLib::AddAssignF(UPARAM(ref) float& Variable, const float add) {
    Variable += add;
}

void UVVAD_UtilsBPLib::SubtAssignF(UPARAM(ref) float& Variable, const float subtract) {
    Variable -= subtract;
}

void UVVAD_UtilsBPLib::DivideAssignF(UPARAM(ref) float& Variable, const float divider) {
    Variable /= divider;
}

void UVVAD_UtilsBPLib::MultiplyAssignF(UPARAM(ref) float& Variable, const float multiplier){
    Variable *= multiplier;
}

void UVVAD_UtilsBPLib::ModuloAssignF(UPARAM(ref) float& Variable, const float modulo) {
    Variable = fmodf(Variable, modulo);
}

int32 UVVAD_UtilsBPLib::NegateInt(const int32 In) {
    return In * -1;
}

int32 UVVAD_UtilsBPLib::IntMinusOne(const int32 In) {
    return In - 1;
}

int32 UVVAD_UtilsBPLib::IntPlusOne(const int32 In) {
    return In + 1;
}

void UVVAD_UtilsBPLib::AddAssignInt(UPARAM(ref)int32& Variable, const int32 add){
    Variable += add;
}

void UVVAD_UtilsBPLib::SubtAssignInt(UPARAM(ref)int32& Variable, const int32 subtract) {
    Variable -= subtract;
}

void UVVAD_UtilsBPLib::DivideAssignInt(UPARAM(ref)int32& Variable, const int32 divider) {
    Variable /= divider;
}

void UVVAD_UtilsBPLib::MultiplyAssignInt(UPARAM(ref)int32& Variable, const int32 multiplier) {
    Variable *= multiplier;
}

void UVVAD_UtilsBPLib::ModuloAssignInt(UPARAM(ref)int32& Variable, const int32 modulo) {
    Variable %= modulo;
}


