#!/usr/bin/python3
import json
import subprocess
import tempfile
import zipfile
import os


def runbackup(item):
    shell = ['coscmd', '-s']
    if(item['bucket']):
        shell.append('-b')
        shell.append(item['bucket'])
    if(item['region']):
        shell.append('-r')
        shell.append(item['region'])
    shell.append('upload')
    if(item['folder']):
        shell.append('-r')
    if(item['sync']):
        shell.append('-s')
    if(item['force']):
        shell.append('-f')
    if(item['skip_confirmation']):
        shell.append('-y')
    if(item['folder'] and len(item['include'])):
        shell.append('--include')
        shell.append(','.join(item['include']))
    elif(item['folder'] and len(item['ignore'])):
        shell.append('--ignore')
        shell.append(','.join(item['ignore']))
    if(item['skipmd5']):
        shell.append('--skipmd5')
    if(item['delete']):
        shell.append('--delete')
    shell.append(item['local_path'])
    shell.append(item['cos_path'])
    subprocess.run(shell)


def nopackbackup(item):
    runbackup(item)


def packbackup(item):
    tmpdir = tempfile.gettempdir()
    aimfile = os.path.join(
        tmpdir, item['cos_path'].split("/")[-1].split("\\")[-1])
    if(os.path.exists(aimfile)):
        os.remove(aimfile)
    if(item['folder']):
        myzipdir(item['local_path'], aimfile)
    else:
        myzipfile(item['local_path'], aimfile)
    item['local_path'] = aimfile
    item['folder'] = False
    runbackup(item)
    os.remove(aimfile)


def backup():
    config = json.load(open("backup.json"))
    for item in config['backup']:
        if(item['packed']):
            packbackup(item)
        else:
            nopackbackup(item)


def myzipdir(dirpath, outfullname):
    zip = zipfile.ZipFile(outfullname, "w", zipfile.ZIP_DEFLATED)
    for path, dirnames, filenames in os.walk(dirpath):
        fpath = path.replace(dirpath, '')
        for filename in filenames:
            zip.write(os.path.join(path, filename),
                      os.path.join(fpath, filename))
    zip.close()


def myzipfile(filepath, outfullname):
    zip = zipfile.ZipFile(outfullname, "w", zipfile.ZIP_DEFLATED)
    zip.write(filepath, filepath.split("/")[-1].split("\\")[-1])
    zip.close()


def main():
    backup()


if __name__ == '__main__':
    main()
