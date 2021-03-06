﻿//==================================================================================================================================//
//!< @file		slGraphicsID.h
//!< @brief		グラフィックスで使用されるID群ヘッダ
//!< @author	T.Haga
//!< @data		作成日時：2017/10/01	更新履歴：2017/10/04
//==================================================================================================================================//

#ifndef SL_GRAPHICS_ID_H
#define SL_GRAPHICS_ID_H

#include "../Utility/slDefine.h"

namespace sl
{

/** TextureIDの構造体 */
SL_DECLARE_ID(TextureID);

/** バーテックスシェーダーIDの構造体 */
SL_DECLARE_ID(VertexShaderID);

/** ピクセルシェーダーIDの構造体 */
SL_DECLARE_ID(PixelShaderID);

/** 頂点レイアウトIDの構造体 */
SL_DECLARE_ID(InputLayoutID);

/** コンスタントバッファーIDの構造体 */
SL_DECLARE_ID(ConstantBufferID);

/** モデルIDの構造体 */
SL_DECLARE_ID(ModelID);

/** UVアニメーションIDの構造体 */
SL_DECLARE_ID(UVAnimeID);

/** 描画のIDをまとめた構造体 */
struct DrawingID
{
	TextureID			m_TextureID;
	VertexShaderID		m_VertexShaderID;
	PixelShaderID		m_PixelShaderID;
	InputLayoutID		m_InputLayoutID;
	ConstantBufferID	m_ConstantBufferID;
	ModelID				m_ModelID;
	UVAnimeID			m_UVAnimeID;
};	// struct DrawingID

}	// namespace sl


#endif	// SL_GRAPHICS_ID_H

//==================================================================================================================================//
// END OF FILE
//==================================================================================================================================//
