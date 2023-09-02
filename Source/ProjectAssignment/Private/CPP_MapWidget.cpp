// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MapWidget.h"

void UCPP_MapWidget::ToggleGameMap()
{
	if (this->IsVisible())
	{
		this->SetVisibility(ESlateVisibility::Hidden); 
	}
	else
	{
		this->SetVisibility(ESlateVisibility::Visible); 
	}
}
