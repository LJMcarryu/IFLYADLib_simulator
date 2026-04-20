//
//  IFLYVideoAd.h
//  IFLYAdLib
//
//  Created by JzProl.m.Qiezi on 2016/12/19.
//  Copyright © 2016年 iflytek. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <IFLYADLib/IFLYAdBase.h>


/// 视频广告类型
typedef NS_ENUM(NSInteger, IFLYVideoAdType) {
    /// 激励视频 — 用户主动选择观看，播放完毕后可获得应用内奖励。通常为全屏竖屏播放，不可跳过
    IFLYVideoAdTypeReward,
    /// 开屏视频 — 在 App 启动时全屏展示的视频广告，支持倒计时跳过
    IFLYVideoAdTypeSplash,
    /// 信息流视频 — 嵌入在信息流列表中的视频广告，支持在 cell 内播放
    IFLYVideoAdTypeNative
};

@class IFLYAdData;
@class IFLYAdError;
@class IFLYVideoAd;

/// 视频广告代理协议
/// @note 所有回调方法均在主线程调用
@protocol IFLYVideoAdDelegate <NSObject>

/// 视频广告加载成功回调
/// @param adData 广告数据对象，包含视频素材及相关信息
/// @discussion 收到此回调后，可调用 showAd 展示广告视图，或调用 startPlay 开始播放
- (void)onVideoAdReceived:(IFLYAdData *)adData;

/// 视频广告加载失败回调
/// @param error 错误对象，包含错误码及描述信息，详见接入手册
- (void)onVideoAdFailed:(IFLYAdError *)error;

@optional

/// 视频广告预加载成功回调
/// @param videoAdData 广告数据对象，包含视频素材及相关信息
/// @param videoSize   视频分辨率（宽 x 高，单位：像素）
/// @discussion 调用 preloadAd 后，视频资源下载完成时触发此回调
- (void)onPreloadSuccess:(IFLYAdData *)videoAdData withSize:(CGSize)videoSize;

/// 视频广告预加载失败回调
/// @param error 错误对象，包含错误码及描述信息
/// @discussion 调用 preloadAd 后，视频资源下载失败时触发此回调
- (void)onPreloadFailed:(IFLYAdError *)error;

/// 视频开始播放回调
/// @discussion 视频首帧渲染到屏幕上时触发
- (void)adStartPlay;

/// 视频播放出错回调
/// @discussion 视频播放过程中发生错误时触发（如解码失败、网络中断等）
- (void)adPlayError;

/// 视频播放完成回调
/// @discussion 视频自然播放结束时触发。对于激励视频，此回调通常表示用户已完整观看，可发放奖励
- (void)adPlayCompleted;

/// 视频重新播放回调
/// @discussion 视频播放完成后用户选择重播时触发
- (void)adReplay;

/// 广告被点击回调
/// @discussion 用户在视频播放过程中点击广告区域时触发
- (void)onVideoAdClicked;

@end


/// 视频广告，继承自 IFLYAdBase
/// @discussion 支持激励视频、开屏视频、信息流视频三种类型。内部集成视频播放器，自动处理播放、曝光和点击。
///             典型接入流程：initWithAdUnitId: → 设置 delegate/currentViewController/fatherView/videoType → loadAd → showAd
@interface IFLYVideoAd : IFLYAdBase

/// 委托对象，用于接收广告加载结果及播放状态回调
/// @note 回调均在主线程触发，delegate 为弱引用
@property (nonatomic, weak) id<IFLYVideoAdDelegate> delegate;

/// 视频播放器的父视图
/// @discussion 视频播放器将添加到此视图上进行播放展示。需与 currentViewController 配合使用：
///             currentViewController 用于弹出落地页，fatherView 用于承载视频播放器
/// @note 必须在调用 showAd 之前设置
@property (nonatomic, weak) UIView *fatherView;

/// 是否静音播放
/// @note 默认为 NO（有声播放）
@property (nonatomic, assign) BOOL mute;

/// 是否自动播放
/// @note 默认为 NO（需手动调用 startPlay 开始播放）
@property (nonatomic, assign) BOOL autoPlay;

/// 视频广告类型
/// @note 必须在调用 loadAd 之前设置，不同类型对应不同的广告行为和 UI 表现
@property (nonatomic, assign) IFLYVideoAdType videoType;

/// cell 播放模式 — 列表滚动视图
/// @discussion 信息流场景下在 UITableView / UICollectionView 的 cell 内播放视频时使用。
///             scrollView、indexPath、fatherViewTag 三个属性必须同时设置，缺一不可
@property (nonatomic, strong) UIScrollView *scrollView;

/// cell 播放模式 — cell 所在的 indexPath
/// @discussion 与 scrollView、fatherViewTag 配合使用，标识视频播放所在的 cell 位置
@property (nonatomic, strong) NSIndexPath *indexPath;

/// cell 播放模式 — 播放器父视图的 tag 值
/// @discussion 与 scrollView、indexPath 配合使用。SDK 根据此 tag 值在指定 cell 中查找目标视图，并将播放器添加到该视图上
@property (nonatomic, assign) NSInteger fatherViewTag;

/// 设置点击视频广告是否直接跳转（不弹出确认）
/// @param value YES 直接跳转，NO 弹出确认（默认）
/// @note 方法名中 "Derect" 为历史拼写，正确拼写应为 "Direct"，为保持向后兼容未做修改
- (void)setDerectJump:(BOOL)value;

/// 视频广告预加载
/// @discussion 预发起广告请求并提前下载视频资源，适用于需要提前缓存视频以提升用户体验的场景。
///             成功时回调 onPreloadSuccess:withSize:，失败时回调 onPreloadFailed:
/// @note 与 loadAd 的区别：preloadAd 会提前下载视频文件，loadAd 仅请求广告数据
- (void)preloadAd;

/// 发起广告请求
/// @discussion [必选] 发起拉取广告请求，广告数据返回后通过 delegate 回调通知。
///             调用前需确保已设置 delegate、currentViewController 和 videoType
/// @note 成功时回调 onVideoAdReceived:，失败时回调 onVideoAdFailed:。
///       与 preloadAd 的区别：loadAd 仅请求广告数据，不预下载视频文件
- (void)loadAd;

/// 展示视频广告视图
/// @discussion 在 loadAd 成功回调后调用。将视频播放器视图添加到 fatherView 上
/// @note 调用前需确保 fatherView 已设置
- (void)showAd;

/// 广告曝光上报 — 基于视图控制器可见性检测
/// @return YES 曝光成功，NO 曝光失败（如视图控制器不可见、重复曝光等）
/// @discussion 内部通过检测 currentViewController 的可见性来判断广告是否真实曝光。
///             一般场景下使用此方法；若广告视图直接添加在 window 上，请使用 attachWindowAd: 替代
/// @note 每个广告仅允许曝光一次，重复调用将返回 NO
- (BOOL)attachAd;

/// 广告曝光上报 — 基于 window 可见性检测
/// @param view 广告所在的视图
/// @return YES 曝光成功，NO 曝光失败
/// @discussion 与 attachAd 功能相同，区别在于内部通过检测 view 所在 window 的可见性来判断广告是否真实曝光。
///             适用于广告视图直接添加在 window 上的场景
/// @note 每个广告仅允许曝光一次，重复调用将返回 NO
- (BOOL)attachWindowAd:(UIView *)view;

/// 广告点击上报
/// @return YES 点击处理成功，NO 点击处理失败
/// @note 当前视频广告内部已集成播放器，播放器会自动处理点击事件，一般情况下无需手动调用此接口
- (BOOL)clickAd;

/// 带扩展信息的广告点击上报
/// @param ext 扩展信息字典，支持 interact/dx/dy/ux/uy/ts 等键值
/// @return YES 点击处理成功，NO 点击处理失败
/// @note 当前视频广告内部已集成播放器，播放器会自动处理点击事件，一般情况下无需手动调用此接口
- (BOOL)clickAdWithExt:(NSDictionary *)ext;

/// 开始播放视频
/// @note 调用前需确保 loadAd 已成功回调且已调用 showAd。若 autoPlay 为 YES，则无需手动调用
- (void)startPlay;

/// 暂停播放视频
/// @note 调用前需确保视频正在播放中
- (void)pausePlay;

/// 恢复播放视频
/// @note 调用前需确保视频处于暂停状态（即已调用过 pausePlay）
- (void)resumePlay;

/// 停止播放视频
/// @discussion 停止播放并释放播放器资源。停止后若需再次播放，需重新调用 loadAd 流程
- (void)stopPlay;

@end
