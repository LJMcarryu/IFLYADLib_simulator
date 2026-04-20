//
//  IFLYAdImgVoiceData.m
//  IFLYAdLib
//
//  Created by JzProl.m.Qiezi on 2016/12/19.
//  Copyright © 2016年 iflytek. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 图片/语音广告素材数据模型
@interface IFLYAdImgVoiceData : NSObject

/// 素材资源 URL
/// @note 必填字段
@property (readonly, nonatomic, strong) NSString *url;
/// 素材宽度，单位：像素
/// @note 非必填
@property (readonly, nonatomic, strong) NSNumber *width;
/// 素材高度，单位：像素
/// @note 非必填
@property (readonly, nonatomic, strong) NSNumber *height;
/// 扩展信息字典
/// @note 非必填
@property (readonly, nonatomic, strong) NSDictionary *ext;

/// 通过字典初始化图片/语音素材数据模型
/// @param dic 素材数据字典（来源于服务端响应）
/// @return 图片/语音素材数据实例
- (instancetype)initWithDic:(NSDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
