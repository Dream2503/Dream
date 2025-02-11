import asyncio

shared_resource: int = 0
lock = asyncio.Lock()


async def modify_shared_resource():
    global shared_resource

    async with lock:
        print(f"Resource before modification: {shared_resource}")
        shared_resource += 1
        await asyncio.sleep(1)
        print(f"Resource after modification: {shared_resource}")


async def main():
    await asyncio.gather(*(modify_shared_resource() for _ in range(5)))


asyncio.run(main())
