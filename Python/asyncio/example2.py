import asyncio


async def fetch_data(delay: int):
    print("Fetching data")
    await asyncio.sleep(delay)
    print("Data fetched")
    return {"data": "Some data"}


async def main():
    print("Start of main coroutine")
    task = fetch_data(2)
    result = await task
    print(f"Received result: {result}")
    print("End of main coroutine")


asyncio.run(main())
