//
//  IFLYAdKeys.h
//  IFLYAdLib
//
//  Created by JzProl.m.Qiezi on 2016/9/26.
//  Copyright © 2016年 iflytek. All rights reserved.
//

/// 广告请求参数 Key 常量
/// @discussion 配合 @c -[IFLYNativeAd setParamValue:forKey:]
///             / @c -[IFLYSplashAd setParamValue:forKey:]
///             / @c -[IFLYVideoAd setParamValue:forKey:] 使用，
///             用于在广告请求前设置各项业务参数。
#ifndef IFLYAdLib_IFLYAdKeys_h
#define IFLYAdLib_IFLYAdKeys_h

typedef NSString *IFLYAdKey NS_STRING_ENUM;

/// 广告位 ID
/// @discussion 用于标识一个广告位，在广告请求时必须设置。
///             值类型：NSString。
extern IFLYAdKey const IFLYAdKeyAdUnitId;

/// 广告请求 ID
/// @discussion 用于外部设置特定的广告请求标识，便于追踪和日志关联。
///             不设置时 SDK 会自动生成唯一请求 ID。
///             值类型：NSString。
extern IFLYAdKey const IFLYAdKeyRequestId;

/// 横幅广告轮询时间间隔
/// @discussion 仅用于横幅广告自动轮询场景。
///             值类型：NSNumber（单位：秒）。
extern IFLYAdKey const IFLYAdKeyBannerInterval;

/// 开屏互动状态
/// @discussion 控制开屏广告的互动行为（如摇一摇、滑动等）。
///             值类型：NSNumber。
///             - @c 1 ：开启开屏互动（默认）
///             - @c 2 ：关闭开屏互动
extern IFLYAdKey const IFLYAdKeyInteractStatus;

/// 交易方式
/// @discussion 指定广告的竞价/交易模式。
///             值类型：NSNumber。
///             - @c 0 ：固定价格流量（默认）
///             - @c 1 ：RTB 竞价模式
///             - @c 2 ：PD 模式（暂不支持）
extern IFLYAdKey const IFLYAdKeySettleType;

/// 竞价底价
/// @discussion 在 CPM 竞价流量（settleType = 1）下该字段必填，
///             表示广告位的最低竞价门槛。
///             值类型：NSNumber（单位：CNY 元/千次展示，即 CPM）。
extern IFLYAdKey const IFLYAdKeyBIDFloor;

/// 竞价成交价
/// @discussion 竞价胜出后的实际成交价格，用于竞价结算上报。
///             值类型：NSNumber（单位：CNY 元）。
extern IFLYAdKey const IFLYAdKeyAuctionPrice;

/// PMP 订单信息
/// @discussion 传入 @c IFLYAdDeal 对象数组，用于 PMP（Private Marketplace）私有交易。
///             每个 @c IFLYAdDeal 包含订单 ID（dealId）和底价（bidFloor）等交易信息。
///             值类型：NSArray<IFLYAdDeal *>。
extern IFLYAdKey const IFLYAdKeyPMP;

/// 应用版本号
/// @discussion 用于设置接入 SDK 的宿主应用版本号，会随广告请求上报。
///             值类型：NSString。
extern IFLYAdKey const IFLYAdKeyAPPVersion;

/// 应用名称
/// @discussion 用于设置接入 SDK 的宿主应用名称，会随广告请求上报。
///             值类型：NSString。
extern IFLYAdKey const IFLYAdKeyAPP;

/// 支持的货币类型
/// @discussion 指定广告交易支持的货币类型，多个类型以逗号分隔。
///             值类型：NSString。
///             - @c CNY ：人民币（默认）
///             - @c USD ：美元
///             示例：@c @"CNY" 或 @c @"CNY,USD"
extern IFLYAdKey const IFLYAdKeyCurrency;

/// 广告请求超时时间
/// @discussion 设置广告请求的超时时间上限。
///             值类型：NSNumber（单位：秒）。
extern IFLYAdKey const IFLYAdKeyRequestTimeout;

/// 浏览器 User-Agent
/// @discussion 用于自定义广告请求中的 UA 字段，传入的值应为浏览器 UA 字符串。
///             值类型：NSString。
extern IFLYAdKey const IFLYAdKeyUA;

/// 广告请求 IDFA
/// @discussion 用于外部传入 IDFA（Identifier for Advertisers）值。
///             值类型：NSString，格式为 @c "00000000-0000-0000-0000-000000000000"。
extern IFLYAdKey const IFLYAdKeyIDFA;

/// CAID 列表（中国广告协会互联网广告标识）
/// @discussion 用于传入由中国广告协会（中广协 / CAA）分配的 CAID 标识列表。
///             值类型：NSArray<NSDictionary *>。
///             每个字典包含 @c ver（版本号）和 @c caid（标识值）两个字段。
///             示例：
///             @code
///             @[@{@"ver": @"20230330", @"caid": @"75c7bc3754b3019c135b526cb8eb4420"},
///               @{@"ver": @"20220111", @"caid": @"8799abe1c76805fab06ee3f98a3f704e"}]
///             @endcode
extern IFLYAdKey const IFLYAdKeyCAIDList;

/// 是否需要录音权限
/// @discussion 控制 SDK 是否在广告请求时获取录音权限状态。
///             值类型：NSNumber（BOOL）。
extern IFLYAdKey const IFLYAdKeyNeedAudio;

/// 是否需要地理位置权限
/// @discussion 控制 SDK 是否在广告请求时获取地理位置权限状态。
///             值类型：NSNumber（BOOL）。
extern IFLYAdKey const IFLYAdKeyNeedLocation;

/// 落地页跳转动画样式
/// @discussion 控制点击广告后打开落地页时的转场动画方向。
///             值类型：NSNumber（NSUInteger）。
///             - @c 0 ：从右侧滑入（默认）
///             - @c 1 ：从底部滑入
extern IFLYAdKey const IFLYAdKeyLandingPageTransitionType;

/// 落地页屏幕旋转方式
/// @discussion 控制落地页支持的设备方向。
///             值类型：NSNumber（NSUInteger）。
///             - @c 0 ：仅竖屏 Portrait（默认）
///             - @c 1 ：仅横屏 Landscape
///             - @c 2 ：支持除 UpsideDown 外的所有方向
///             - @c 3 ：支持所有方向
extern IFLYAdKey const IFLYAdKeyLandingPageAutorotateType;

/// DeepLink 是否直接跳转
/// @discussion 设置 DeepLink 跳转时是否跳过 @c canOpenURL 检查直接调用 @c openURL。
///             值类型：NSNumber（BOOL），默认 @c YES。
/// @note 此参数目前仅对原生广告（IFLYNativeAd）和视频广告（IFLYVideoAd）生效。
extern IFLYAdKey const IFLYAdKeyJumpDirectly;

#endif /* IFLYAdLib_IFLYAdKeys_h */
