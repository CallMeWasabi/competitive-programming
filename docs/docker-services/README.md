# ใช้ Redis / Postgres / MongoDB / Message Queue ผ่าน Docker

## สถานะเครื่องตอนนี้ (2026-11-22)

| Service (Windows) | Port | ตอนนี้ |
|---|---|---|
| `postgresql-x64-18` | 5432 | **Stopped**, StartType = Manual |
| `MongoDB` | 27017 | **Stopped**, StartType = Manual |

ไม่ได้ uninstall และข้อมูลเดิมยังอยู่ครบ ถ้าต้องการกลับมาใช้แบบเดิม ให้รันใน PowerShell แบบ Admin:

```powershell
Set-Service postgresql-x64-18 -StartupType Automatic; Start-Service postgresql-x64-18
```

ถ้าแน่ใจแล้วว่าไม่ใช้แบบ native อีก ค่อย uninstall ผ่าน Settings → Apps ทีหลังได้

## เริ่มใช้งาน

1. เปิด **Docker Desktop** ก่อนเสมอ (ถ้าไม่เปิด `docker` จะ error ว่า `dockerDesktopLinuxEngine` not found)
2. เข้าโฟลเดอร์นี้ แล้วเปิดเฉพาะตัวที่จะใช้:

```powershell
docker compose --profile pg up -d
```

| profile | service | ต่อจากเครื่องด้วย |
|---|---|---|
| `pg` | PostgreSQL 18 | `postgresql://dev:dev@localhost:5432/dev` |
| `redis` | Redis 8 | `redis://localhost:6379` |
| `mongo` | MongoDB 8 | `mongodb://dev:dev@localhost:27017` |
| `mq` | RabbitMQ 4 | `amqp://dev:dev@localhost:5672`, UI: http://localhost:15672 |
| `kafka` | Kafka 4.1 (KRaft) | `localhost:9092` |
| `all` | ทั้งหมด | |

คำสั่งที่ใช้บ่อย:

```powershell
docker compose --profile all ps
```

```powershell
docker compose --profile pg logs -f postgres
```

```powershell
docker compose exec postgres psql -U dev
```

```powershell
docker compose exec redis redis-cli
```

```powershell
docker compose --profile all down
```

`down -v` จะลบ volume (ข้อมูลหายหมด) ใช้ตอนอยากรีเซ็ตให้สะอาด

## Resource สำหรับเรียน (เรียงตามลำดับที่แนะนำ)

### 1. พื้นฐาน Docker
- **Docker Get Started (official)**: https://docs.docker.com/get-started/ อ่านส่วน concepts (image, container, volume, network) ให้เข้าใจก่อน
- **Docker Compose docs**: https://docs.docker.com/compose/ โดยเฉพาะหัวข้อ *profiles*, *volumes*, *healthcheck*
- **TechWorld with Nana: Docker Tutorial for Beginners** (YouTube) ภาพรวมดี ใช้เวลาประมาณ 3 ชม.
- **Play with Docker**: https://labs.play-with-docker.com/ ลองคำสั่งได้บน browser

### 2. หน้า image ทางการบน Docker Hub (สำคัญมาก ทุก env var อยู่ที่นี่)
- https://hub.docker.com/_/postgres
- https://hub.docker.com/_/redis
- https://hub.docker.com/_/mongo
- https://hub.docker.com/_/rabbitmq
- https://hub.docker.com/r/apache/kafka

### 3. เรียนตัว service เอง
- **PostgreSQL**: official tutorial https://www.postgresql.org/docs/current/tutorial.html และ https://www.postgresqltutorial.com/
- **Redis**: Redis University (ฟรี) https://university.redis.io/ และ data types https://redis.io/docs/latest/develop/data-types/
- **MongoDB**: MongoDB University (ฟรี) https://learn.mongodb.com/
- **RabbitMQ**: official tutorials 1–7 (มีหลายภาษา) https://www.rabbitmq.com/tutorials ใช้คู่กับ `--profile mq` ได้เลย
- **Kafka**: quickstart https://kafka.apache.org/quickstart และคอร์สฟรีของ Confluent https://developer.confluent.io/courses/

### 4. แนวทางฝึก
1. เปิด Postgres ด้วย compose → ต่อด้วย `psql` / DBeaver → ลอง `down` แล้ว `up` ใหม่ ดูว่าข้อมูลยังอยู่ (volume) แล้วลอง `down -v`
2. เขียนโปรแกรมเล็ก ๆ ที่ใช้ Postgres + Redis (เช่น cache ผลลัพธ์ query)
3. ทำ RabbitMQ tutorial 1–3 (hello world → work queues → pub/sub)
4. ลองเขียน `compose.yaml` ของตัวเองที่มี app + db ใน network เดียวกัน (ภายใน network จะต่อด้วยชื่อ service เช่น `postgres:5432` ไม่ใช่ `localhost`)
