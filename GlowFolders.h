
#include <UIKit/UIKit.h>

/*

Header(s) *meow*

*/

@class MTMaterialView, SBFolderIconBackgroundView, UIView, _SBIconGridWrapperView, NSMutableArray, SBFloatyFolderView, NSString;

@interface MTMaterialView : UIView
@property (nonatomic,assign,readwrite,getter=isBlurEnabled) BOOL blurEnabled;
@end

@interface SBFolderIconImageView : UIView {

	SBFolderIconBackgroundView* _backgroundView;
	UIView* _solidColorBackgroundView;
	UIView* _pageGridContainer;
	_SBIconGridWrapperView* _leftWrapperView;
	_SBIconGridWrapperView* _rightWrapperView;
	NSMutableArray* _pageElements;
	unsigned long long _currentPageIndex;
	SBFloatyFolderView* _crossfadeFolderView;
	UIView* _crossfadeScalingView;
	BOOL _animating;
	unsigned long long _imageUpdatesDisableCount;
	unsigned long long _transitionToken;
	unsigned long long _backgroundStyle;
	unsigned long long _currentBackgroundStyle;
}
@property (nonatomic,readonly) unsigned long long concreteBackgroundStyle; 
@property (assign,nonatomic) unsigned long long currentBackgroundStyle;                 //@synthesize currentBackgroundStyle=_currentBackgroundStyle - In the implementation block

@property (assign,nonatomic) unsigned long long backgroundStyle;                        //@synthesize backgroundStyle=_backgroundStyle - In the implementation block

@property (nonatomic,readonly) unsigned long long currentPageIndex;                     //@synthesize currentPageIndex=_currentPageIndex - In the implementation block
@property (readonly) unsigned long long hash; 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (copy,readonly) NSString * debugDescription; 
-(void)_updateOverlayImage;
-(void)scrollToFirstGapAnimated:(BOOL)arg1 ;
-(void)folderIcon:(id)arg1 didUpdateGridImage:(id)arg2 forListIndex:(unsigned long long)arg3 forContainedIconImageUpdate:(id)arg4 ;
-(Class)_iconGridImageClass;
-(CGRect)frameForMiniIconAtIndex:(unsigned long long)arg1 ;
-(unsigned long long)firstVisibleMiniIconIndex;
-(id)_folderIcon;
-(void)_updateRasterization;
-(void)_updateAccessibilityBackgroundContrast;
-(void)_updateCurrentBackgroundStyle;
-(void)_setPageElements:(id)arg1 ;
-(void)scrollToTopOfFirstPageAnimated:(BOOL)arg1 ;
-(void)setBackgroundAndIconGridImageAlpha:(double)arg1 ;
-(CGSize)_interiorGridSizeClipRect;
-(CGSize)_interPageSpacing;
-(void)scrollToTopOfPage:(unsigned long long)arg1 animated:(BOOL)arg2 ;
-(void)_performScrollingMovingToLeft:(BOOL)arg1 movingToRight:(BOOL)arg2 targetPageIndex:(unsigned long long)arg3 targetPageScrollRow:(unsigned long long)arg4 newLeftElement:(id)arg5 newRightElement:(id)arg6 animated:(BOOL)arg7 ;
-(id)_currentPageElement;
-(unsigned long long)visibleMiniIconCount;
-(CGRect)frameForMiniIconAtIndexPath:(id)arg1 ;
-(void)setWallpaperRelativeCenter:(CGPoint)arg1 ;
-(void)setFloatyFolderCrossfadeFraction:(double)arg1 ;
-(void)updateImageAnimated:(BOOL)arg1 ;
-(unsigned long long)currentBackgroundStyle;
-(unsigned long long)concreteBackgroundStyle;
-(void)setCurrentBackgroundStyle:(unsigned long long)arg1 ;
-(void)_showLeftMinigrid;
-(void)_showRightMinigrid;
-(void)setIcon:(id)arg1 location:(long long)arg2 animated:(BOOL)arg3 ;
-(void)_setupGridViewsInDefaultConfiguration;
-(void)blurryBackgroundViewDidChangeWhetherBlurring:(id)arg1 ;
-(id)_generateSquareContentsImage;
-(id)darkeningOverlayImage;
-(void)scrollToGapOrTopIfFullOfPage:(unsigned long long)arg1 animated:(BOOL)arg2 ;
-(unsigned long long)visibleMiniIconListIndex;
-(unsigned long long)centerVisibleMiniIconIndex;
-(unsigned long long)lastVisibleMiniIconIndex;
-(CGRect)visibleImageRelativeFrameForMiniIconAtIndex:(unsigned long long)arg1 ;
-(void)setIconGridImageAlpha:(double)arg1 ;
-(void)setSuppressesBlurryBackgroundChanges:(BOOL)arg1 ;
-(void)prepareToCrossfadeWithFloatyFolderView:(id)arg1 allowFolderInteraction:(BOOL)arg2 ;
-(void)cleanupAfterFloatyFolderCrossfade;
-(void)disableImageUpdates;
-(void)enableImageUpdates;
-(id)initWithFrame:(CGRect)arg1 ;
-(void)layoutSubviews;
-(void)dealloc;
-(unsigned long long)backgroundStyle;
-(void)setBackgroundStyle:(unsigned long long)arg1 ;
-(id)snapshot;
-(id)backgroundView;
-(void)_setAnimating:(BOOL)arg1 ;
-(void)prepareForReuse;
-(id)contentsImage;
-(unsigned long long)currentPageIndex;
-(void)setBackgroundScale:(double)arg1 ;
@end