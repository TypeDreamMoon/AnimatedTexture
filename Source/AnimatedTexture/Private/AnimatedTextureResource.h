/**
 * Copyright 2019 Neil Fang. All Rights Reserved.
 *
 * Animated Texture from GIF file
 *
 * Created by Neil Fang
 * GitHub: https://github.com/neil3d/UAnimatedTexture5
 *
*/

#pragma once

#include "CoreMinimal.h"
#include "TextureResource.h"	// Engine

class UAnimatedTexture2D;

/**
 * FTextureResource implementation for animated 2D textures
 * @see clss FTexture2DDynamicResource
 */
class FAnimatedTextureResource : public FTextureResource
{
public:
	FAnimatedTextureResource(UAnimatedTexture2D* InOwner);

	//~ Begin FTextureResource Interface.
	virtual uint32 GetSizeX() const override;
	virtual uint32 GetSizeY() const override;
	virtual void InitRHI(FRHICommandListBase& RHICmdList) override;
	virtual void ReleaseRHI() override;
	//~ End FTextureResource Interface.

private:
	int32 GetDefaultMipMapBias() const;

	void CreateSamplerStates(float MipMapBias);

private:
	UAnimatedTexture2D* Owner;
};
