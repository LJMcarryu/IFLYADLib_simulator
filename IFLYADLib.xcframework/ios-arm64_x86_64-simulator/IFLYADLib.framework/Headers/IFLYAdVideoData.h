//
//  IFLYAdVideoData.h
//  IFLYAdLib
//
//  Created by JzProl.m.Qiezi on 2016/12/19.
//  Copyright © 2016年 iflytek. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 视频广告素材数据模型
@interface IFLYAdVideoData : NSObject

/// 视频资源 URL
/// @note 必填字段
@property (readonly, nonatomic, strong) NSString *url;
/// 视频时长，单位：秒
/// @note 非必填
@property (readonly, nonatomic, strong) NSNumber *duration;
/// 视频宽度，单位：像素
/// @note 非必填
@property (readonly, nonatomic, strong) NSNumber *width;
/// 视频高度，单位：像素
/// @note 非必填
@property (readonly, nonatomic, strong) NSNumber *height;
/// 视频码率，单位：kbps
/// @note 非必填
@property (readonly, nonatomic, strong) NSNumber *bitrate;
/// 视频格式
/// @note 非必填。取值范围：0=mp4，1=3gp，2=avi，3=flv
@property (readonly, nonatomic, strong) NSNumber *format;
/// 缓存过期时间戳，单位：秒（Unix 时间戳，超过该时间后本地缓存失效）
/// @note 非必填
@property (readonly, nonatomic, strong) NSNumber *end_time;
/// 扩展信息字典
/// @note 非必填
@property (readonly, nonatomic, strong) NSDictionary *ext;

/// 通过字典初始化视频素材数据模型
/// @param dic 视频素材数据字典（来源于服务端响应）
/// @return 视频素材数据实例
- (instancetype)initWithDic:(NSDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
