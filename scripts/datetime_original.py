from exif import Image
import os
import time

# 将文件名中的时间信息写入图片 exif 中
def filenameInphoto(folderpath):
    files = os.listdir(folderpath)

    for filename in files:
        if not filename.lower().endswith(('.bmp', '.dib', '.png', '.jpg', '.jpeg', '.pbm', '.pgm', '.ppm', '.tif', '.tiff')):
            continue
        print(filename)

        fullpath = os.path.join(folderpath, filename)
        with open(fullpath, 'rb') as img_file:
            img = Image(img_file)
        # QQ图片2015 05 01 15 54 40
        if len(filename) > 18 and filename[:4] == 'QQ图片':
            datetime = filename[4:8] + ':' + filename[8:10] + ':' + filename[10:12] + ' ' + filename[12:14] + ':' + filename[14:16] + ':' + filename[16:18]
        # wx_camera_1602860805390
        elif len(filename) > 23 and filename[:9] == 'wx_camera':
            datetime = time.strftime("%Y:%m:%d %H:%M:%S", time.localtime(int(filename[10:20])))
        # mmexport1610118682343
        elif len(filename) > 21 and filename[:8] == 'mmexport':
            datetime = time.strftime("%Y:%m:%d %H:%M:%S", time.localtime(int(filename[8:18])))
        else:
            continue
        img.datetime_original = datetime
        with open(fullpath, 'wb') as new_image_file:
            new_image_file.write(img.get_file())

# 将指定信息写入 exif 中
def ChangeDate(folderpath, datetime):
    files = os.listdir(folderpath)
    for filename in files:
        if not filename.lower().endswith(('.bmp', '.dib', '.png', '.jpg', '.jpeg', '.pbm', '.pgm', '.ppm', '.tif', '.tiff')):
            continue
        print(filename)

        fullpath = os.path.join(folderpath, filename)
        with open(fullpath, 'rb') as img_file:
            img = Image(img_file)
        img.datetime_original = datetime
        with open(fullpath, 'wb') as new_image_file:
            new_image_file.write(img.get_file())

ChangeDate('2015暑假', '2015:07:03 11:12:10')
filenameInphoto('2015暑假')