## 01 build.gradle.kts(Project)
这是一个Gradle的脚本文件，位于Android项目的根目录中，它包含适用于所有子项目和模块的配置设置。因此，此文件为所有模块定义了通用配置。它指定了整个项目中要使用的插件，集中管理依赖项版本，可以添加自定义 Gradle 任务等等。
## 02 build.gradle.kts(Module)
```
plugins {  
    alias(libs.plugins.android.application)  
}  
```

**插件部分**：它应用了Android开发所需的插件

```  
android {  
    namespace = "com.chengfy.firstkotlinprogram"  
    compileSdk {  
        version = release(36) {  
            minorApiLevel = 1  
        }  
    }  
    defaultConfig {  
        applicationId = "com.chengfy.firstkotlinprogram"  
        minSdk = 24  
        targetSdk = 36  
        versionCode = 1  
        versionName = "1.0"  
  
        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"  
    }  
  
    buildTypes {  
        release {  
            optimization {  
                enable = false  
            }  
        }    }    compileOptions {  
        sourceCompatibility = JavaVersion.VERSION_11  
        targetCompatibility = JavaVersion.VERSION_11  
    }  
}  
```

**Android块**：This is where you define all the **essential parameters** thar determine **how your android application will be built.** 
**namespace**：the unique **package identifier** for the app.（只在编译阶段的包名）
**compileSDK**：specifies which Android SDK version to compile against.
`defaultConfig`：所有构建变体（debug/release）共用的基础配置
1. `applicationId`：**应用 ID**，手机系统识别 APP 的唯一标识，发布到应用商店靠这个，和包名可以不一样
2. `minSdk = 24`：**最低支持 Android 版本**，24 = Android 7.0；低于这个版本的手机不能安装你的 App
3. `targetSdk = 36`：**目标 SDK**，告诉系统：你已经适配好了 Android 16 的行为特性；系统会按 Android16 规则运行你的 App（权限、后台限制等）
4. `versionCode`：内部版本号，**整数**，每次发版必须递增，商店识别升级用，用户看不见
5. `versionName`：版本名称，字符串，给用户看的版本号如`1.0`
6. `testInstrumentationRunner`：Android 仪器化测试的运行器，用于跑 androidTest 下的 UI 测试

`buildTypes`：构建类型，默认自带`debug`、`release`
- `release`：正式包配置
- `optimization.enable = false`：**关闭 release 的代码优化（R8 / 混淆压缩）**

>[!warning]
开发调试 release 包时方便看代码；上线时一定要打开，减小包体积、混淆代码。

```
dependencies {  
    implementation(libs.androidx.activity.ktx)  
    implementation(libs.androidx.appcompat)  
    implementation(libs.androidx.constraintlayout)  
    implementation(libs.androidx.core.ktx)  
    implementation(libs.material)  
    testImplementation(libs.junit)  
    androidTestImplementation(libs.androidx.espresso.core)  
    androidTestImplementation(libs.androidx.junit)  
}
```

`dependencies`：依赖库声明块

> `libs.xxx` 是 Version Catalog，版本统一管理在`libs.versions.toml`，不用在这个文件写死版本号

- `implementation`：编译 + 运行都需要的库，打包进 APK
    - `androidx.core.ktx`：Android 核心扩展，Kotlin 扩展函数
    - `androidx.appcompat`：兼容库，让新版控件在低版本 Android 可用
    - `androidx.activity.ktx`：Activity Kotlin 扩展
    - `constraintlayout`：约束布局
    - `material`：Material Design 组件库
- `testImplementation`：**单元测试依赖**，只在`test/`目录下代码可用，不会打进 APK（JUnit）
- `androidTestImplementation`：**仪器化测试依赖**，`androidTest/`下，在真机 / 模拟器跑 UI 测试（Espresso、androidx JUnit）