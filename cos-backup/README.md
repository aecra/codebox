# 腾讯云 COS 文件备份脚本

## 描述

该脚本用于文件备份，使用腾讯云官方提供的 `coscmd` 脚本来实现上传支持，目前支持的功能有：

- 上传文件

- 上传文件夹

- md5 校验上传

- Unix 风格文件过滤

- 文件打包上传

- 文件夹打包上传

## 如何使用

1. 安装 python3

2. 安装 coscmd

   ```bash
     pip install coscmd
   ```

3. 配置 coscmd

   ```bash
       coscmd config -a 公钥 -s 密钥 -b 默认存储桶 -r 默认地域
   ```

4. 配置 backup.json

   ```json
   {
     "backup": [
       {
         "bucket": "backup-1255835707",
         "region": "ap-beijing",
         "folder": true,
         "local_path": "C:/Users/aecra/Desktop",
         "cos_path": "Desktop",
         "sync": true,
         "force": false,
         "skip_confirmation": true,
         "include": [],
         "ignore": ["*/node_modules/*", "*/build/*"],
         "skipmd5": false,
         "delete": true
       },
       {
         "bucket": "backup-1255835707",
         "region": "ap-beijing",
         "folder": true,
         "local_path": "F:/workspace",
         "cos_path": "workspace",
         "sync": true,
         "force": false,
         "skip_confirmation": true,
         "include": [],
         "ignore": ["*/node_modules/*", "*/build/*"],
         "skipmd5": false,
         "delete": true
       },
       {
         "bucket": "backup-1255835707",
         "region": "ap-beijing",
         "folder": false,
         "packed": true,
         "local_path": "F:/clash/config.yaml",
         "cos_path": "dabao/clash.zip",
         "sync": true,
         "force": false,
         "skip_confirmation": true,
         "skipmd5": false,
         "delete": true
       }
     ]
   }
   ```

5. 执行脚本

   ```bash
     python backup.py
   ```

## 缺点

暂不支持打包备份模式下的 Unix 风格文件过滤。
