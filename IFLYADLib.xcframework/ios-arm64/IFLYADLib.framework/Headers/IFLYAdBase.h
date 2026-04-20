//
//  IFLYAdBase.h
//  IFLYADLib
//
//  Base class for NativeAd and VideoAd, providing shared properties and methods.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 广告基类，为 IFLYNativeAd 和 IFLYVideoAd 提供公共属性与方法
@interface IFLYAdBase : NSObject

/// 当前视图控制器，用于展示广告落地页
/// @note 必须在调用 loadAd 之前设置，否则落地页无法正常弹出
@property (nonatomic, weak) UIViewController *currentViewController;

/// 落地页跳转视图控制器
/// @note 可选设置。若未设置，默认使用 currentViewController 来展示落地页
@property (nonatomic, weak) UIViewController *jumperViewController;

/// 构造方法
/// @param adUnitId 广告位 ID，由讯飞广告平台分配，格式如 @"xxxxxx"
/// @return IFLYAdBase 实例
- (instancetype)initWithAdUnitId:(NSString *)adUnitId;

/// 设置广告配置参数
/// @param value 参数值
/// @param key   参数键名，应使用 IFLYAdKeys.h 中定义的 IFLYAdKey 常量
- (void)setParamValue:(NSObject *)value forKey:(NSString *)key;

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

/// 设置是否禁用 DeepLink 跳转
/// @param disable YES 禁用 DeepLink 跳转，NO 启用（默认值）
/// @note 默认为 NO，即允许 DeepLink 跳转。设置为 YES 后，点击广告将不再尝试 DeepLink，直接使用浏览器打开落地页
- (void)setDeepLinkDisable:(BOOL)disable;

/// 广告点击跳转完成回调
/// @discussion 当用户点击广告并完成跳转（打开落地页/应用商店/Safari）后触发。
///             success 为 YES 表示跳转成功，NO 表示跳转失败
@property (nonatomic, copy) void (^ _Nullable didJumpBlock)(BOOL success);

/// 广告退出落地页的回调
/// @discussion 在用户点击广告跳转后，关闭内嵌浏览器落地页时触发。
///             与 dismissStoreBlock 互斥 — 同一次点击只会触发其中一个
@property (nonatomic, copy) void (^ _Nullable dismissBlock)(void);

/// 广告退出应用商店的回调
/// @discussion 在用户点击广告跳转后，关闭应用内 App Store 页面时触发。
///             与 dismissBlock 互斥 — 同一次点击只会触发其中一个
@property (nonatomic, copy) void (^ _Nullable dismissStoreBlock)(void);

/// 离开应用回调
/// @discussion 当发生 DeepLink 跳转或用户进入后台离开 App 时触发。
///             此回调独立于其他回调，不影响 didJumpBlock / dismissBlock 等回调的触发
@property (nonatomic, copy) void (^ _Nullable didLeaveApp)(void);

@end

NS_ASSUME_NONNULL_END
