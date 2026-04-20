//
//  IFLYADLib.h
//  IFLYADLib
//
//  Created by admin on 27.2.25.
//

/// IFLYADLib -- 讯飞广告 SDK
/// @discussion 提供原生广告、开屏广告、视频广告能力。
///             主要入口类：IFLYNativeAd / IFLYSplashAd / IFLYVideoAd

#import <Foundation/Foundation.h>

//! Project version number for IFLYADLib.
FOUNDATION_EXPORT double IFLYADLibVersionNumber;

//! Project version string for IFLYADLib.
FOUNDATION_EXPORT const unsigned char IFLYADLibVersionString[];

#pragma mark - model  数据模型
#import <IFLYADLib/IFLYAdData.h>
#import <IFLYADLib/IFLYAdImgVoiceData.h>
#import <IFLYADLib/IFLYAdMonitorData.h>
#import <IFLYADLib/IFLYAdVideoData.h>

#pragma mark - biz  广告类型
#import <IFLYADLib/IFLYNativeAd.h>
#import <IFLYADLib/IFLYVideoAd.h>
#import <IFLYADLib/IFLYSplashAd.h>

#pragma mark - tools  工具与配置
#import <IFLYADLib/IFLYAdConfig.h>
#import <IFLYADLib/IFLYAdKeys.h>
#import <IFLYADLib/IFLYAdTool.h>
#import <IFLYADLib/IFLYAdError.h>


