#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <IFLYADLib/IFLYAdBase.h>


@class IFLYAdData;
@class IFLYAdError;
@class IFLYNativeAd;

/// 原生广告代理协议
/// @note 所有回调方法均在主线程调用
@protocol IFLYNativeAdDelegate <NSObject>

/// 原生广告加载成功回调
/// @param adData 广告数据对象，包含素材信息（图片/文字/视频等）
/// @discussion 收到此回调后，使用 adData 中的素材数据渲染广告视图，渲染完成后调用 attachAd: 进行曝光
- (void)onNativeAdReceived:(IFLYAdData *)adData;

/// 原生广告加载失败回调
/// @param error 错误对象，包含错误码及描述信息，详见接入手册
- (void)onNativeAdFailed:(IFLYAdError *)error;

@end


/// 原生广告，继承自 IFLYAdBase
/// @discussion 原生广告由媒体侧自行渲染 UI，SDK 负责数据获取、曝光上报和点击跳转。
///             典型接入流程：initWithAdUnitId: → 设置 delegate/currentViewController → loadAd → 渲染 UI → attachAd: → clickAd:
@interface IFLYNativeAd : IFLYAdBase

/// 委托对象，用于接收广告加载结果回调
/// @note 回调均在主线程触发，delegate 为弱引用
@property (nonatomic, weak) id<IFLYNativeAdDelegate> delegate;

/// 发起广告请求
/// @discussion [必选] 发起拉取广告请求，广告数据返回后通过 delegate 回调通知。
///             调用前需确保已设置 delegate 和 currentViewController
/// @note 成功时回调 onNativeAdReceived:，失败时回调 onNativeAdFailed:
- (void)loadAd;

/// 广告曝光上报 — 基于视图控制器可见性检测
/// @param view 渲染完成的广告视图
/// @return YES 曝光成功，NO 曝光失败（如视图控制器不可见、重复曝光等）
/// @discussion [必选] 广告数据渲染完毕即将展示时调用。内部通过检测 currentViewController 的可见性来判断广告是否真实曝光。
///             一般场景下使用此方法；若广告视图直接添加在 window 上（如开屏场景），请使用 attachWindowAd: 替代
/// @note 每个广告仅允许曝光一次，重复调用将返回 NO
- (BOOL)attachAd:(UIView *)view;

/// 广告曝光上报 — 基于 window 可见性检测
/// @param view 渲染完成的广告视图
/// @return YES 曝光成功，NO 曝光失败
/// @discussion [必选] 与 attachAd: 功能相同，区别在于内部通过检测 view 所在 window 的可见性来判断广告是否真实曝光。
///             适用于广告视图直接添加在 window 上的场景（如开屏广告）
/// @note 每个广告仅允许曝光一次，重复调用将返回 NO
- (BOOL)attachWindowAd:(UIView *)view;

/// 广告点击上报
/// @param view 被点击的广告视图
/// @return YES 点击处理成功（将弹出落地页），NO 点击处理失败（如广告未曝光）
/// @discussion 当用户点击广告时，开发者需调用本方法。SDK 将根据广告数据弹出内嵌浏览器、应用内 App Store 或系统 Safari 展示落地页
- (BOOL)clickAd:(UIView *)view;

/// 带扩展信息的广告点击上报
/// @param ext 扩展信息字典，支持以下键值：
///            - @"interact" : 交互类型
///            - @"dx"       : 按下时的 x 坐标
///            - @"dy"       : 按下时的 y 坐标
///            - @"ux"       : 抬起时的 x 坐标
///            - @"uy"       : 抬起时的 y 坐标
///            - @"ts"       : 点击时间戳
/// @return YES 点击处理成功，NO 点击处理失败
/// @discussion 功能与 clickAd: 相同，额外支持传递用户交互信息用于反作弊上报
- (BOOL)clickAdWithExt:(NSDictionary *)ext;

/// 广告点击跳转动画开始回调
/// @discussion 用户点击广告后，落地页弹出动画开始时触发（在主线程）
@property (nonatomic, copy) void (^ clickAdAnimateStartBlock)(void);

/// 广告点击跳转动画结束回调
/// @discussion 用户点击广告后，落地页弹出动画结束时触发（在主线程）
@property (nonatomic, copy) void (^ clickAdAnimateCompleteBlock)(void);

/// 广告落地页关闭动画开始回调
/// @discussion 用户关闭落地页时，关闭动画开始时触发（在主线程）
@property (nonatomic, copy) void (^ closeAdAnimateStartBlock)(void);

/// 广告落地页关闭动画结束回调
/// @discussion 用户关闭落地页时，关闭动画结束时触发（在主线程）
@property (nonatomic, copy) void (^ closeAdAnimateCompleteBlock)(void);


@end
