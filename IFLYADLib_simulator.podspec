Pod::Spec.new do |spec|

  spec.name         = "IFLYADLib_simulator"
  spec.version      = "5.5.3"
  spec.summary      = "(含模拟器版本)科大讯飞消费者BG-AI营销-ADX广告SDK-IFLYADLib."
  spec.description  = <<-DESC
(含模拟器版本)科大讯飞消费者BG-AI营销-ADX广告SDK-IFLYADLib.使用OC实现
                   DESC

  spec.homepage     = "https://github.com/LJMcarryu/IFLYADLib_simulator"
  spec.license = { :type => "MIT", :file => "LICENSE" }
  spec.author             = { "jmliu6" => "jmliu6@iflytek.com" }
  spec.platform     = :ios, "13.0"
  spec.source       = { :git => "https://github.com/LJMcarryu/IFLYADLib_simulator.git", :tag => "#{spec.version}" }

  spec.ios.vendored_frameworks = 'IFLYADLib.xcframework'

  spec.static_framework = true
  spec.resource  = "IFLYADLib.xcframework/ios-arm64/IFLYADLib.framework/IFLYPlayer.bundle"

end
