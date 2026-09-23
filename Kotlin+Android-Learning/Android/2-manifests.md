```xml
<?xml version="1.0" encoding="utf-8"?>  
<manifest xmlns:android="http://schemas.android.com/apk/res/android"  
    xmlns:tools="http://schemas.android.com/tools">  
  
    <application  
        android:allowBackup="true"  
        android:dataExtractionRules="@xml/data_extraction_rules"  
        android:fullBackupContent="@xml/backup_rules"  
        android:icon="@mipmap/ic_launcher"  
        android:label="@string/app_name"  
        android:roundIcon="@mipmap/ic_launcher_round"  
        android:supportsRtl="true"  
        android:theme="@style/Theme.FirstKotlinProgram">  
        <activity  
            android:name=".MainActivity"  
            android:exported="true"  
            android:windowSoftInputMode="adjustResize">  
            <intent-filter>  
                <action android:name="android.intent.action.MAIN" />  
  
                <category android:name="android.intent.category.LAUNCHER" />  
            </intent-filter>  
        </activity>  
    </application>  
  
</manifest>
```

## 01 userpermission
```xml
<uses-permission android:name="android.permission.ACCESS_WIFI_STATE"/>
```
**向系统声明，你的 App 需要使用这个权限。**
1. **告诉系统 / 应用商店：App 有使用该能力的意图** 清单声明是**必要前提**；不写，哪怕你代码写动态申请也拿不到权限。
2. **区分两种权限**
    - **普通权限（Normal）**：只需要写 `<uses-permission>`，安装时自动授予，不用弹窗。例如 `INTERNET`、`ACCESS_NETWORK_STATE`。
    - **危险权限（Dangerous，Android6.0+ / API23+）**： ✅ 清单里**必须声明** `<uses-permission>` ✅ **代码里还必须动态申请**（`Activity.requestPermissions`），弹出窗口让用户手动同意；用户随时可以在系统设置关闭。例如相机、位置、通讯录。
3. **和 `<permission>` 的区别（很容易搞混）**
    - `<uses-permission>`：**我要使用别人定义的权限**（绝大多数开发场景）
    - `<permission>`：**我自己定义一个新权限，保护我自己 App 内的组件**，很少用。