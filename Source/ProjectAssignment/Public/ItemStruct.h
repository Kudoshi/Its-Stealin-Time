// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemStruct.generated.h"


/**
 * 
 */
class PROJECTASSIGNMENT_API ItemStruct
{
public:
	ItemStruct();
	~ItemStruct();
};

//-------------

UENUM(BlueprintType)
enum ItemCategoryEnum
{
	KITCHENWARE UMETA(DisplayName = "KITCHENWARE"),
	APPLIANCES UMETA(DisplayName = "APPLIANCES"),
	ELECTRONICS UMETA(DisplayName = "ELECTRONICS"),
	DECORATION UMETA(DisplayName = "DECORATION"),
	ACCESSORIES UMETA(DisplayName = "ACCESSORIES"),
	FOOD UMETA(DisplayName = "FOOD"),
	PLAYER_ITEM UMETA(DisplayName = "PLAYER_ITEM"),

};
//
//USTRUCT(BlueprintType)
//struct FBook
//{
//	GENERATED_USTRUCT_BODY()
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere)
//		FString name;
//	UPROPERTY(BlueprintReadWrite, EditAnywhere)
//		int numberofPages;
//	UPROPERTY(BlueprintReadWrite, EditAnywhere)
//		float rating;
//};



USTRUCT(BlueprintType)
struct FGameItem
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString itemName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int itemValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TEnumAsByte<ItemCategoryEnum> itemCategory; // Changed the type to ItemCategoryEnum

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float itemSlow;
	 

}; 

 