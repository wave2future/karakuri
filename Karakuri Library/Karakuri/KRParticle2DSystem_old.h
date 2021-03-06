/*!
    @file   KRParticle2DSystem.h
    @author numata
    @date   09/08/07
 
    Please write the description of this class.
 */

#pragma once

#include <Karakuri/Karakuri.h>
#include <AvailabilityMacros.h>


#define KR_PARTICLE2D_USE_POINT_SPRITE  0


struct _KRParticle2DGenInfo_old {
    KRVector2D  centerPos;
    int         count;
};


const int _KRParticle2DGenMaxCount_old = 20;


class _KRParticle2D_old : public KRObject {
    
public:
    unsigned    mLife;
    unsigned    mBaseLife;
    KRVector2D  mPos;
    KRVector2D  mV;
    KRVector2D  mGravity;
    KRColor     mColor;
    double      mSize;
    
    double      mDeltaSize;
    double      mDeltaRed;
    double      mDeltaGreen;
    double      mDeltaBlue;
    double      mDeltaAlpha;
    
public:
	_KRParticle2D_old(unsigned life, const KRVector2D& pos, const KRVector2D& v, const KRVector2D& gravity, const KRColor& color, double size,
                  double deltaRed, double deltaGreen, double deltaBlue, double deltaAlpha, double deltaSize);
    
public:
    bool    step();
    
public:
    virtual std::string to_s() const;

};

/*!
    @class  KRParticle2DSystem
    @group  Game Graphics
    @deprecated
    @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
    <p>2次元の移動を行うパーティクル群を生成し管理するための仕組みです。<br/>
    火、爆発、煙、雲、霧などの表現に利用できます。</p>
 */
class KRParticle2DSystem : public KRObject {
    
    std::list<_KRParticle2D_old*>   mParticles;

    unsigned        mLife;
    KRVector2D      mStartPos;
    
    KRTexture2D*    mTexture;
    bool            mHasInnerTexture;
    
    KRVector2D      mMinV;
    KRVector2D      mMaxV;
    KRVector2D      mGravity;
    
    unsigned        mParticleCount;
    int             mGenerateCount;
    
    KRBlendMode     mBlendMode;
    
    KRColor         mColor;
    double          mDeltaSize;
    double          mDeltaRed;
    double          mDeltaGreen;
    double          mDeltaBlue;
    double          mDeltaAlpha;
    
    bool            mDoLoop;
    _KRParticle2DGenInfo_old    mGenInfos[_KRParticle2DGenMaxCount_old];
    int             mActiveGenCount;
    
#if KR_PARTICLE2D_USE_POINT_SPRITE
    double          mSize;
#else
    double          mMinSize;
    double          mMaxSize;
#endif
    
public:
    /*!
        @task コンストラクタ
     */
    
    /*!
        @method KRParticle2DSystem
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>テクスチャに使用する画像ファイルの名前を指定して、このパーティクル・システムを生成します。</p>
        <p>デフォルトでは、addGenerationPoint() 関数を用いて、単発生成を行います。</p>
        <p>doLoop 引数に true を指定することで、パーティクルを無限に生成し続けるようになります。</p>
     */
    KRParticle2DSystem(const std::string& filename, bool doLoop=false) DEPRECATED_ATTRIBUTE;

    /*!
        @method KRParticle2DSystem
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>テクスチャを指定して、このパーティクル・システムを生成します。</p>
        <p>このコンストラクタを利用することにより、同じテクスチャを異なる複数のパーティクル・システムで共有して効率的に使うことができます。同じ画像でサイズが異なるパーティクルを生成したい場合などに、このコンストラクタを利用してください。</p>
        <p>デフォルトでは、addGenerationPoint() 関数を用いて、単発生成を行います。</p>
        <p>doLoop 引数に true を指定することで、パーティクルを無限に生成し続けるようになります。</p>
     */
    KRParticle2DSystem(KRTexture2D* texture, bool doLoop=false) DEPRECATED_ATTRIBUTE;
    virtual ~KRParticle2DSystem() DEPRECATED_ATTRIBUTE;
    
private:
    void    init();
    
public:
    /*!
        @task 実行のための関数
     */
    
    /*!
        @method draw
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>このパーティクル・システムで生成されたすべてのパーティクルを描画します。</p>
     */
    void    draw() DEPRECATED_ATTRIBUTE;
    
    /*!
        @method step
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>設定に基づいて必要なパーティクルを生成し、生成されたすべてのパーティクルを動かします。基本的に、1フレームに1回この関数を呼び出してください。</p>
     */
    void    step() DEPRECATED_ATTRIBUTE;

public:
    /*!
        @task ループ実行のための関数
     */
    
    /*!
        @method getStartPos
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>ループ実行時のパーティクルの生成時の位置を取得します。</p>
     */
    KRVector2D  getStartPos() const DEPRECATED_ATTRIBUTE;
    
    /*!
        @method setStartPos
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>ループ実行時のパーティクルの生成時の位置を設定します。</p>
     */
    void    setStartPos(const KRVector2D& pos) DEPRECATED_ATTRIBUTE;
    
public:
    /*!
        @task 単発実行のための関数
     */
    
    /*!
        @method addGenerationPoint
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>新しいパーティクル生成ポイントを指定された座標に追加します。</p>
        <p>setParticleCount() 関数で設定された最大個数だけパーティクルを生成した時点で、その生成ポイントは削除されます。</p>
     */
    void    addGenerationPoint(const KRVector2D& pos) DEPRECATED_ATTRIBUTE;

public:
    /*!
        @task 設定のための関数
     */

    /*!
        @method setBlendMode
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクルを描画するためのブレンドモードを設定します。</p>
        <p>デフォルトのブレンドモードは、KRBlendModeAddition に設定されています。</p>
     */
    void    setBlendMode(KRBlendMode blendMode) DEPRECATED_ATTRIBUTE;
    
    /*!
        @method setColor
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクル描画時に適用される初期カラーを設定します。</p>
     */
    void    setColor(const KRColor& color) DEPRECATED_ATTRIBUTE;
    
    /*!
        @method setColorDelta
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクルの生存期間の割り合い（0.0〜1.0）に応じた、各色成分の変化の割り合いを設定します。</p>
     */
    void    setColorDelta(double red, double green, double blue, double alpha) DEPRECATED_ATTRIBUTE;
    
    /*!
        @method setGenerateCount
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>1フレーム（1回の step() 関数呼び出し）ごとのパーティクルの最大生成個数を設定します。</p>
        <p>マイナスの値を設定すると、それ以降パーティクルは生成されなくなります。</p>
     */
    void    setGenerateCount(int count) DEPRECATED_ATTRIBUTE;
    
    /*!
        @method setGravity
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>各パーティクルの1フレーム（1回の step() 関数呼び出し）ごとに適用される加速度を設定します。</p>
        <p>デフォルトでは加速度は (0.0, 0.0) に設定されています。</p>
     */
    void    setGravity(const KRVector2D& a) DEPRECATED_ATTRIBUTE;
    
    /*!
        @method setLife
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>各パーティクルの生存期間を設定します。</p>
        <p>既に生成されているパーティクルには影響を及ぼしません。デフォルトの生存期間は、60フレーム（=1秒）です。</p>
     */
    void    setLife(unsigned life) DEPRECATED_ATTRIBUTE;
    
    /*!
        @method setMaxV
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクル生成時にランダムで設定される移動速度の最大値を設定します。</p>
     */
    void    setMaxV(const KRVector2D& v) DEPRECATED_ATTRIBUTE;
    
    /*!
        @method setMinV
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクル生成時にランダムで設定される移動速度の最小値を設定します。</p>
     */
    void    setMinV(const KRVector2D& v) DEPRECATED_ATTRIBUTE;
    
    /*!
        @method setParticleCount
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクルの最大個数を設定します。</p>
        <p>デフォルトの設定では256個です。</p>
     */
    void    setParticleCount(unsigned count) DEPRECATED_ATTRIBUTE;
    
    /*!
        @method setSizeDelta
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクルの生存期間の割り合い（0.0〜1.0）に応じた、サイズの変化の割り合いを設定します。</p>
     */
    void    setSizeDelta(double value) DEPRECATED_ATTRIBUTE;
    
#if KR_PARTICLE2D_USE_POINT_SPRITE
    void    setSize(double size) DEPRECATED_ATTRIBUTE;
#else
    /*!
        @method setMaxSize
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>各パーティクルの生成時の最大サイズを設定します。</p>
     */
    void    setMaxSize(double size) DEPRECATED_ATTRIBUTE;

    /*!
        @method setMinSize
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>各パーティクルの生成時の最小サイズを設定します。</p>
     */
    void    setMinSize(double size) DEPRECATED_ATTRIBUTE;    
#endif
    
public:
    /*!
        @task 現在の設定を確認するための関数
     */
    
    /*!
        @method getBlendMode
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクルを描画するためのブレンドモードを取得します。</p>
     */
    KRBlendMode getBlendMode() const DEPRECATED_ATTRIBUTE;
    
    /*!
        @method getColor
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクル描画時に適用される初期カラーを取得します。</p>
     */
    KRColor     getColor() const DEPRECATED_ATTRIBUTE;

    /*!
        @method getDeltaAlpha
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクルの生存期間の割り合い（0.0〜1.0）に応じたアルファ成分の変化の割り合いを取得します。</p>
     */
    double      getDeltaAlpha() const DEPRECATED_ATTRIBUTE;

    /*!
        @method getDeltaBlue
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクルの生存期間の割り合い（0.0〜1.0）に応じた青成分の変化の割り合いを取得します。</p>
     */
    double      getDeltaBlue() const DEPRECATED_ATTRIBUTE;

    /*!
        @method getDeltaGreen
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクルの生存期間の割り合い（0.0〜1.0）に応じた緑成分の変化の割り合いを取得します。</p>
     */
    double      getDeltaGreen() const DEPRECATED_ATTRIBUTE;

    /*!
        @method getDeltaRed
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクルの生存期間の割り合い（0.0〜1.0）に応じた赤成分の変化の割り合いを取得します。</p>
     */
    double      getDeltaRed() const DEPRECATED_ATTRIBUTE;
    
    /*!
        @method getDeltaSize
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクルの生存期間の割り合い（0.0〜1.0）に応じたサイズの変化の割り合いを取得します。</p>
     */
    double      getDeltaSize() const DEPRECATED_ATTRIBUTE;
    
    /*!
        @method getGenerateCount
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>1フレーム（1回の step() 関数呼び出し）ごとのパーティクルの最大生成個数を取得します。</p>
     */
    int         getGenerateCount() const DEPRECATED_ATTRIBUTE;
    
    /*!
        @method getGeneratedParticleCount
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>現時点で生成されているパーティクルの個数を取得します。</p>
     */
    unsigned    getGeneratedParticleCount() const DEPRECATED_ATTRIBUTE;
    
    /*!
        @method getGravity
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>各パーティクルの1フレーム（1回の step() 関数呼び出し）ごとに適用される加速度を取得します。</p>
     */
    KRVector2D  getGravity() const DEPRECATED_ATTRIBUTE;
    
    /*!
        @method getLife
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>各パーティクルの生存期間を取得します。</p>
     */
    unsigned    getLife() const DEPRECATED_ATTRIBUTE;
    
    /*!
        @method getMaxV
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクル生成時にランダムで設定される移動速度の最大値を取得します。</p>
     */
    KRVector2D  getMaxV() const DEPRECATED_ATTRIBUTE;
    
    /*!
        @method getMinV
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクル生成時にランダムで設定される移動速度の最小値を取得します。</p>
     */
    KRVector2D  getMinV() const DEPRECATED_ATTRIBUTE;
    
    /*!
        @method getParticleCount
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>パーティクルの最大個数を取得します。</p>
     */
    unsigned    getParticleCount() const DEPRECATED_ATTRIBUTE;
    
public:
#if KR_PARTICLE2D_USE_POINT_SPRITE
    double      getSize() const DEPRECATED_ATTRIBUTE;
#else
    /*!
        @method getMaxSize
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>各パーティクルの生成時の最大サイズを取得します。</p>
     */
    double      getMaxSize() const DEPRECATED_ATTRIBUTE;
    
    /*!
        @method getMinSize
        @abstract   <strong class="warning">(Deprecated) 現在、このクラスの利用は推奨されません。代わりに、Karakuri Box アプリケーションと KRAnime2DManager クラスを利用してください。</strong>
        <p>各パーティクルの生成時の最小サイズを取得します。</p>
     */
    double      getMinSize() const DEPRECATED_ATTRIBUTE;
#endif
    
public:
    virtual std::string to_s() const;

} DEPRECATED_ATTRIBUTE;


