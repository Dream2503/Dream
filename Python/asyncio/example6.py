import asyncio


async def fetch_data(id: int, sleep_time: int):
    print(f"Coroutine {id} starting to fetch data.")
    await asyncio.sleep(sleep_time)
    return {"id": id, "data": f"Sample data from coroutine {id}"}


async def main():
    results = await asyncio.gather(fetch_data(1, 2), fetch_data(2, 1), fetch_data(3, 3))

    for result in results:
        print(f"Received result: {result}")


asyncio.run(main())
