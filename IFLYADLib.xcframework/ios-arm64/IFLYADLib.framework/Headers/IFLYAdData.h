//
//  IFLYAdData.h
//  IFLYAdLib
//
//  Created by JzProl.m.Qiezi on 2016/12/19.
//  Copyright © 2016年 iflytek. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IFLYAdHtmlData;
@class IFLYAdImgVoiceData;
@class IFLYAdAudioData;
@class IFLYAdVideoData;
@class IFLYAdMonitorData;

NS_ASSUME_NONNULL_BEGIN

/// 广告数据模型，包含广告素材、交互参数、监测数据等完整广告信息
@interface IFLYAdData : NSObject

/// 广告模板 ID
@property (readonly, nonatomic, strong) NSNumber *template_id;
/// 广告创意 ID
@property (readonly, nonatomic, strong) NSString *creative_id;
/// 广告出价，单位：分
@property (readonly, nonatomic, strong) NSNumber *price;
/// PMP 交易 ID（Private Marketplace）
@property (readonly, nonatomic, strong) NSString *deal_id;
/// H5 广告数据
@property (readonly, nonatomic, strong) IFLYAdHtmlData *html;
/// 广告主图素材
@property (readonly, nonatomic, strong) IFLYAdImgVoiceData *img;
/// 图片素材 1（多图广告场景）
@property (readonly, nonatomic, strong) IFLYAdImgVoiceData *img1;
/// 图片素材 2（多图广告场景）
@property (readonly, nonatomic, strong) IFLYAdImgVoiceData *img2;
/// 图片素材 3（多图广告场景）
@property (readonly, nonatomic, strong) IFLYAdImgVoiceData *img3;
/// 视频素材
@property (readonly, nonatomic, strong) IFLYAdVideoData *video;
/// 音频素材
@property (readonly, nonatomic, strong) IFLYAdAudioData *audio;
/// 交互类型
/// @note 取值范围：1=点击，2=点击+摇一摇，3=点击+上滑，4=点击+摇一摇+上滑
@property (readonly, nonatomic, strong) NSNumber *interact;
/// 点击类型
/// @note 取值范围：0=区域可点，1=全屏可点
@property (readonly, nonatomic, strong) NSNumber *click_type;
/// 摇一摇参数
/// @note 字典包含 acc（灵敏度）和 angle（旋转角度）
@property (readonly, nonatomic, strong) NSDictionary *shake_info;
/// 广告标题
@property (readonly, nonatomic, strong) NSString *title;
/// 广告描述
@property (readonly, nonatomic, strong) NSString *desc;
/// 应用图标素材
@property (readonly, nonatomic, strong) IFLYAdImgVoiceData *icon;
/// 广告正文内容
@property (readonly, nonatomic, strong) NSString *content;
/// CTA 按钮文字（Call-to-Action，如"立即下载""了解更多"）
@property (readonly, nonatomic, strong) NSString *ctatext;
/// 应用名称（应用下载类广告）
@property (readonly, nonatomic, strong) NSString *app_name;
/// 应用下载量（应用下载类广告）
@property (readonly, nonatomic, strong) NSNumber *downloads;
/// 应用评分（应用下载类广告）
@property (readonly, nonatomic, strong) NSString *rating;
/// 应用下载地址（应用下载类广告）
@property (readonly, nonatomic, strong) NSString *app_download_url;
/// 应用介绍页地址（应用下载类广告）
@property (readonly, nonatomic, strong) NSString *app_intro_url;
/// 应用版本号（应用下载类广告）
@property (readonly, nonatomic, strong) NSString *app_ver;
/// 应用包大小，单位：字节（应用下载类广告）
@property (readonly, nonatomic, strong) NSNumber *app_size;
/// 电话号码（电话拨打类广告）
@property (readonly, nonatomic, strong) NSString *phone;
/// 点赞数
@property (readonly, nonatomic, strong) NSNumber *likes;
/// 原价
@property (readonly, nonatomic, strong) NSNumber *original_price;
/// 现价
@property (readonly, nonatomic, strong) NSNumber *current_price;
/// 赞助商名称
@property (readonly, nonatomic, strong) NSString *sponsored;
/// 地址信息
@property (readonly, nonatomic, strong) NSString *address;
/// 应用 ID（应用下载类广告）
@property (readonly, nonatomic, strong) NSString *app_id;
/// 应用包名（应用下载类广告）
@property (readonly, nonatomic, strong) NSString *package_name;
/// 品牌名称
@property (readonly, nonatomic, strong) NSString *brand;
/// 展示标签数组
@property (readonly, nonatomic, strong) NSArray *display_labels;
/// 语音广告素材
@property (readonly, nonatomic, strong) IFLYAdImgVoiceData *voice_ad;
/// 关闭按钮图标 URL
@property (readonly, nonatomic, strong) NSString *close_icon;
/// 广告监测数据
@property (readonly, nonatomic, strong) IFLYAdMonitorData *monitor;
/// DeepLink 跳转地址
@property (readonly, nonatomic, strong) NSString *deeplink;
/// 落地页 URL
@property (readonly, nonatomic, strong) NSString *landing;
/// 点击行为类型
@property (readonly, nonatomic, strong) NSString *action_type;
/// 广告来源图标 URL
@property (readonly, nonatomic, strong) NSString *ad_source_icon;
/// 广告来源标记文字
@property (readonly, nonatomic, strong) NSString *ad_source_mark;
/// 扩展信息字典
@property (readonly, nonatomic, strong) NSDictionary *ext;

/// 通过字典初始化广告数据模型
/// @param dic 广告数据字典（来源于服务端响应）
/// @return 广告数据实例
- (instancetype)initWithDic:(NSDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
