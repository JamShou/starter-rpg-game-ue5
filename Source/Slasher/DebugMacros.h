#pragma once
#include "DrawDebugHelpers.h"

#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Magenta, false, 0.f);
#define DRAW_SPHERE_SingleFrame(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Magenta, false, -1.f);

//Both required for line and point
#define DRAW_DEBUG_FORWARD_LINE(Location) if (GetWorld()) DrawDebugLine(GetWorld(), Location, Location + GetActorForwardVector() * 100.f, FColor::Red, false);
#define DRAW_DEBUG_FORWARD_LINE_SingleFrame(Location) if (GetWorld()) DrawDebugLine(GetWorld(), Location, Location + GetActorForwardVector() * 100.f, FColor::Red, false, -1.f);

#define DRAW_POINT(Location) if (GetWorld()) DrawDebugPoint(World, Location + Forward * 100.f, 15.f, FColor::Red, true);
#define DRAW_POINT_SingleFrame(Location) if (GetWorld()) DrawDebugPoint(World, Location + Forward * 100.f, 15.f, FColor::Red, false, -1.f);

#define DRAW_DEBUG_ORIGIN_LINE(Location) if (GetWorld()) DrawDebugLine(GetWorld(), Location, FVector::ZeroVector, FColor::Blue, false);
#define DRAW_VECTOR(StartLocation, EndLocation) if (GetWorld()) \
{ \
DrawDebugLine(GetWorld(), Location, Location + GetActorForwardVector() * 100.f, FColor::Red, false); \
DrawDebugPoint(World, Location + Forward * 100.f, 15.f, FColor::Red, true); \
}
#define DRAW_VECTOR_SingleFrame(StartLocation, EndLocation) if (GetWorld()) \
{ \
DrawDebugLine(GetWorld(), Location, Location + GetActorForwardVector() * 100.f, FColor::Red, false,-1.f, 0, 1.f); \
DrawDebugPoint(World, Location + Forward * 100.f, 15.f, FColor::Red, false, -1.f); \
}