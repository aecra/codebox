import os
import time
import requests


def checknet():
    url = "http://www.baidu.com"
    try:
        res = requests.get(url)
        if res.status_code == 200:
            print("网络正常")
            return True
        print("网络连接错误")
        return False
    except:
        print("网络连接错误")
        return False


def net_link():
    os.system("@Rasdial 校园网 /DISCONNECT")

    # 然后重新拨号
    admin = '账号'
    passward = '密码'

    os.system("@Rasdial 校园网 " + admin + " " + passward)


def main():
    while True:

        print("重新检测")

        # 有网络
        if checknet():
            pass

        # 没网络
        else:
            net_link()

        if checknet() == True:
            # 有网
            time.sleep(10)


if __name__ == "__main__":
    main()
