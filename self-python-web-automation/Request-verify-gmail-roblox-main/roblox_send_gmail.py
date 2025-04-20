import requests
import re
import time

def is_valid_email(email):
    email_regex = r'^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$'
    return re.match(email_regex, email) is not None

# โหลดอีเมลจากไฟล์ email.txt
def load_email_from_file(file_path):
    with open(file_path, "r", encoding="utf-8") as file:
        email = file.readline().strip()  # อ่านอีเมลจากบรรทัดแรกและลบช่องว่างที่ไม่จำเป็น
    if not email:
        print("❌ อีเมลในไฟล์ไม่สามารถอ่านได้หรือไม่มีข้อมูล")
        return None
    if not is_valid_email(email):
        print("❌ รูปแบบอีเมลไม่ถูกต้อง")
        return None
    return email


# ฟังก์ชันดึง CSRF Token
def get_csrf_token(session):
    res = session.post("https://auth.roblox.com/v2/logout")
    if res.status_code == 403:
        return res.headers.get("x-csrf-token")
    return None

# ฟังก์ชันการผูกอีเมล
def attach_email(cookie, email):
    session = requests.Session()
    session.cookies['.ROBLOSECURITY'] = cookie
    session.headers.update({
        "User-Agent": "Roblox/WinInet",
        "Referer": "https://www.roblox.com/",
        "X-CSRF-TOKEN": ""
    })

    csrf = get_csrf_token(session)
    if not csrf:
        print("  [!] ไม่สามารถดึง CSRF Token ได้")
        return
    session.headers['X-CSRF-TOKEN'] = csrf

    res = session.get("https://users.roblox.com/v1/users/authenticated")
    if res.status_code != 200:
        print("  ❌ Cookie ใช้งานไม่ได้")
        return
    username = res.json().get("name")
    print(f"  ✅ เข้าสู่ระบบสำเร็จ: {username}")

    payload = {
        "emailAddress": email
    }

    res = session.post("https://accountsettings.roblox.com/v1/email", json=payload)

    if res.status_code == 200:
        print(f"  ✅ ส่งคำขอยืนยันไปที่ {email}")
    else:
        print(f"  ❌ ผูกอีเมลล้มเหลว ({res.status_code}): {res.text}")

# โหลด cookie.txt (จาก path เดิมหรือแก้ได้)
cookie_path = "cookie.txt"
with open(cookie_path, "r", encoding="utf-8") as cf:
    lines = cf.readlines()

# ✅ กรองเฉพาะ cookie ที่ขึ้นต้นด้วย _| และยาวพอ
cookies = [line.strip() for line in lines if line.strip().startswith("_|") and len(line.strip()) > 50]

# โหลดอีเมลจาก email.txt
email_path = "email.txt"
email = load_email_from_file(email_path)

print(f"📨 ใช้อีเมล:{email}")
print(f"🔁 พบ {len(cookies)} cookie(s)\n")

# ดำเนินการกับ cookie แต่ละอัน
for i, cookie in enumerate(cookies, 1):
    print(f"[{i}] ดำเนินการกับ cookie...")
    attach_email(cookie, email)
    print("-" * 50)
    time.sleep(10)