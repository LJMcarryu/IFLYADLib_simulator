//
//  IFLYSplashAd.h
//  IFLYAdLib
//
//  Created by jmliu6 on 2023/5/10.
//  Copyright © 2023 iflytek. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class IFLYAdData;
@class IFLYAdError;

/// 开屏广告代理协议
/// @note 所有回调方法均在主线程调用
@protocol IFLYSplashAdDelegate <NSObject>

/// 开屏广告加载成功回调
/// @param adData 广告数据对象，包含素材信息
/// @discussion 收到此回调后，可调用 showAd 展示开屏广告，或通过 getAdCallbackDic 获取物料信息用于竞价决策
- (void)onSplashAdReceived:(IFLYAdData *)adData;

/// 开屏广告加载失败回调
/// @param error 错误对象，包含错误码及描述信息，详见接入手册
- (void)onSplashAdFailed:(IFLYAdError *)error;

@end

/// 开屏广告
/// @discussion 开屏广告为全屏展示的广告形式，支持图片和视频素材，通常在 App 启动时展示。
///             典型接入流程：initWithAdUnitId: → 设置 delegate → loadAd → showAd
@interface IFLYSplashAd : NSObject

/// 委托对象，用于接收广告加载结果回调
/// @note 回调均在主线程触发，delegate 为弱引用
@property (nonatomic, weak) id<IFLYSplashAdDelegate> delegate;

/// 构造方法
/// @param adUnitId 广告位 ID，由讯飞广告平台分配，格式如 @"xxxxxx"
/// @return IFLYSplashAd 实例
- (instancetype)initWithAdUnitId:(NSString *)adUnitId;

/// 设置广告配置参数
/// @param value 参数值
/// @param key   参数键名，应使用 IFLYAdKeys.h 中定义的 IFLYAdKey 常量
- (void)setParamValue:(NSObject *)value forKey:(NSString *)key;

/// 媒体自定义展示 Window
/// @discussion 用于多窗口场景（如 iPad 多任务、外接屏幕等）。设置后，开屏广告将展示在指定的 window 上而非默认 keyWindow。
///             一般单窗口场景无需设置
@property (nonatomic, strong) UIWindow *customWindow;

/// 广告倒计时时长（单位：秒）
/// @note 有效范围为 3 ~ 5 秒，默认值为 5 秒。设置超出范围的值将被自动修正为最近的边界值
@property (nonatomic, assign) NSInteger traceDuration;

/// 媒体自定义底部视图
/// @discussion 设置后将在开屏广告底部展示该自定义视图（如 App Logo 区域）。视图高度由媒体自行控制，广告区域会自适应剩余空间
@property (nonatomic, strong) UIView *mediumBottomView;

/// 是否禁止摇一摇交互功能
/// @note 默认为 NO（不禁止）。设置为 YES 后，即使广告返回的 shake_info 中包含摇一摇配置，也不会启用摇一摇交互
@property (nonatomic, assign) BOOL disableShaking;

/// 媒体定制：是否显示"免除广告"按钮
/// @discussion 设置为 YES 后，开屏广告界面将展示"免除广告"按钮。用户点击该按钮后会触发 didNoAdsBlock 回调，
///             但 SDK 内部不执行任何操作（关闭广告、跳转等由媒体侧自行处理）
@property (nonatomic, assign) BOOL showNoAds;

/// 发起广告请求
/// @discussion [必选] 发起拉取广告请求，广告数据返回后通过 delegate 回调通知。
///             调用前需确保已设置 delegate
/// @note 成功时回调 onSplashAdReceived:，失败时回调 onSplashAdFailed:
- (void)loadAd;

/// 展示开屏广告
/// @discussion 在 loadAd 成功回调后调用。内部自动处理广告曝光上报，无需额外调用 attach 方法。
///             广告将展示在 customWindow（若已设置）或默认 keyWindow 上
/// @note 展示结果通过 didShowBlock / didShowFailedBlock 回调通知
- (void)showAd;

/// 广告竞价胜出通知
///
/// 在广告竞价（Header Bidding）场景下，媒体侧需在竞价结果确定后调用此方法通知 SDK。
///
/// type 取值说明：
/// | type | 含义 |
/// |------|------|
/// | 100  | 获胜竞得 |
/// | 101  | 未获胜 — 出价低 |
/// | 102  | 未获胜 — 素材未审核 |
/// | 103  | 未获胜 — 素材审核拒绝 |
/// | 104  | 未获胜 — 竞价优先级低（如 PDB > PD > RTB） |
/// | 105  | 竞价响应错误 |
/// | 106  | 竞价响应超时 |
///
/// @param type   竞价结果类型，取值见上表
/// @param reason 自定义原因描述，内容需进行 URL Encode。当 type=103 时，建议填写具体审核拒绝原因
- (void)sendWinNoticeWithType:(NSNumber *)type reason:(NSString *)reason;

/// 获取广告请求成功后的物料信息（媒体定制）
/// @return 包含广告物料信息的字典，可用于竞价决策。广告未加载成功时返回空字典
/// @discussion 返回的字典中包含广告竞价相关的字段（如价格、素材类型等），具体键值定义详见接入手册
- (NSDictionary *)getAdCallbackDic;

/// 广告展示成功回调
/// @discussion showAd 调用后，广告视图成功展示到屏幕上时触发（在主线程）。
///             与 didShowFailedBlock 互斥 — 同一次展示只会触发其中一个
@property (nonatomic, copy) void (^ didShowBlock)(void);

/// 广告展示失败回调
/// @discussion showAd 调用后，广告视图展示失败时触发（在主线程）。
///             与 didShowBlock 互斥 — 同一次展示只会触发其中一个
@property (nonatomic, copy) void (^ didShowFailedBlock)(void);

/// 广告倒计时结束回调
/// @discussion 开屏广告倒计时自然结束时触发（在主线程）。
///             与 didSkipBlock、didJumpBlock 互斥 — 仅在倒计时正常结束时调用，用户跳过或点击跳转不会触发
@property (nonatomic, copy) void (^ didCloseBlock)(void);

/// 广告跳过回调
/// @discussion 用户点击"跳过"按钮时触发（在主线程），此回调也代表广告结束。
///             与 didCloseBlock、didJumpBlock 互斥
@property (nonatomic, copy) void (^ didSkipBlock)(void);

/// 广告点击跳转完成回调
/// @discussion 用户点击广告并完成跳转后触发（在主线程），此回调也代表广告结束。
///             success 为 YES 表示跳转成功，NO 表示跳转失败。
///             与 didCloseBlock、didSkipBlock 互斥
@property (nonatomic, copy) void (^ didJumpBlock)(BOOL success);

/// 广告退出落地页的回调
/// @discussion 在用户点击广告跳转后，关闭内嵌浏览器落地页时触发（在主线程）。
///             与 dismissStoreBlock 互斥 — 同一次点击只会触发其中一个
@property (nonatomic, copy) void (^ dismissBlock)(void);

/// 广告退出应用商店的回调
/// @discussion 在用户点击广告跳转后，关闭应用内 App Store 页面时触发（在主线程）。
///             与 dismissBlock 互斥 — 同一次点击只会触发其中一个
@property (nonatomic, copy) void (^ dismissStoreBlock)(void);

/// 离开应用回调
/// @discussion 当发生 DeepLink 跳转或用户进入后台离开 App 时触发（在主线程）。
///             此回调独立于其他回调，不影响 didCloseBlock / didSkipBlock / didJumpBlock 等回调的触发
@property (nonatomic, copy) void (^ didLeaveApp)(void);

/// "免除广告"按钮点击回调（媒体定制）
/// @discussion 用户点击"免除广告"按钮时触发（在主线程）。SDK 内部不执行任何操作，媒体侧需自行处理后续逻辑（如关闭广告、跳转会员页等）。
///             此回调独立于其他回调，不影响其他回调的触发
/// @note 仅在 showNoAds 设置为 YES 时生效
@property (nonatomic, copy) void (^ didNoAdsBlock)(void);

@end

NS_ASSUME_NONNULL_END
