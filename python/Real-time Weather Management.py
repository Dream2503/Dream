from typing import Literal


def api_request(location: str, days: int = 1) -> dict:
    from http.client import HTTPSConnection
    api_key = "a7a8b6ffa17b4cddbc4165700241004"
    api_url = f"/v1/forecast.json?key={api_key}&q={location}&days={days}"
    connection = HTTPSConnection("api.weatherapi.com")
    connection.request("GET", api_url)
    req = connection.getresponse()
    json = eval(req.read().decode("utf-8"))
    return json


def convert(itype: Literal["dir", "vis"], ipt: str) -> str:
    if itype == "dir":
        directions = {
            "N": "North",
            "NNE": "North-Northeast",
            "NE": "Northeast",
            "ENE": "East-Northeast",
            "E": "East",
            "ESE": "South-Southeast",
            "SE": "Southeast",
            "SSE": "South-Southeast",
            "S": "South",
            "SSW": "South-Southwest",
            "SW": "Southwest",
            "WSW": "West-Southwest",
            "W": "West",
            "WNW": "West-Northwest",
            "NW": "Northwest",
            "NNW": "North-Northwest",
        }

        try:
            return directions[ipt]
        except KeyError:
            return ipt + " (unexpected error)"

    elif itype == "vis":
        if ipt == "kph":
            return "km"
        else:
            return "miles"


def display_current_report(data: dict) -> None:
    rtn = {
        "Name": data["location"]["name"],
        "State": data["location"]["region"],
        "Country": data["location"]["country"],
        "Date and Time": data["location"]["localtime"],
        "Last Updated": data["current"]["last_updated"],
        "Actual Temperature": str(data["current"][f"temp_{TEMP_UNIT}"]) + TEMP_UNIT.upper(),
        "Feels Like Temperature": str(data["current"][f"feelslike_{TEMP_UNIT}"]) + TEMP_UNIT.upper(),
        "Climate Condition": data["current"]["condition"]["text"],
        "Wind Speed": str(data["current"][f"wind_{SPD_UNIT}"]) + SPD_UNIT,
        "Wind Degree": data["current"]["wind_degree"],
        "Wind Direction": convert("dir", data["current"]["wind_dir"]),
        "Pressure": str(data["current"]["pressure_mb"]) + f" millibars",
        "Precipitation": str(data["current"][f"precip_{PPT_UNIT}"]) + PPT_UNIT,
        "Humidity": str(data["current"]["humidity"]) + "%",
        "Visibility": str(data["current"][f"vis_{convert('vis', SPD_UNIT)}"]) + convert("vis", SPD_UNIT),
        "UV Index": data["current"]["uv"],
    }
    print("\nCURRENT WEATHER REPORT")

    for key, value in rtn.items():
        print(f"{key} --> {value}")

    input("\nPress any key to continue...")


def display_forecast_report(data: dict, iday: int, is_hourly: bool = False) -> None:
    forecast_day = []
    forecast_hour = []

    for i in range(iday):
        forecast_day.append({
            "Name": data["location"]["name"],
            "State": data["location"]["region"],
            "Country": data["location"]["country"],
            "Date and Time": data["forecast"]["forecastday"][i]["date"],
            "Maximum Temperature": str(
                data["forecast"]["forecastday"][i]["day"][f"maxtemp_{TEMP_UNIT}"]) + TEMP_UNIT.upper(),
            "Minimum Temperature": str(
                data["forecast"]["forecastday"][i]["day"][f"mintemp_{TEMP_UNIT}"]) + TEMP_UNIT.upper(),
            "Average Temperature": str(
                data["forecast"]["forecastday"][i]["day"][f"avgtemp_{TEMP_UNIT}"]) + TEMP_UNIT.upper(),
            "Maximum Wind Speed": str(data["forecast"]["forecastday"][i]["day"][f"maxwind_{SPD_UNIT}"]) + SPD_UNIT,
            "Total Precipitation": str(data["forecast"]["forecastday"][i]["day"][f"totalprecip_{PPT_UNIT}"]) + PPT_UNIT,
            "Average Visibility": str(
                data["forecast"]["forecastday"][i]["day"][f"avgvis_{convert('vis', SPD_UNIT)}"]) + convert('vis',
                                                                                                           SPD_UNIT),
            "Average Humidity": str(data["forecast"]["forecastday"][i]["day"]["avghumidity"]) + "%",
            "Climate Condition": data["forecast"]["forecastday"][i]["day"]["condition"]["text"],
            "UV Index": data["forecast"]["forecastday"][i]["day"]["uv"],
            "Sunrise": data["forecast"]["forecastday"][i]["astro"]["sunrise"],
            "Sunset": data["forecast"]["forecastday"][i]["astro"]["sunset"],
            "Moonrise": data["forecast"]["forecastday"][i]["astro"]["moonrise"],
            "Moonset": data["forecast"]["forecastday"][i]["astro"]["moonset"],
            "Moon Phase": data["forecast"]["forecastday"][i]["astro"]["moon_phase"],
        })

        if is_hourly:
            hourly = []

            for j in range(24):
                hourly.append({
                    "Time": data["forecast"]["forecastday"][i]["hour"][j]["time"][-5::],
                    "Actual Temperature": str(
                        data["forecast"]["forecastday"][i]["hour"][j][f"temp_{TEMP_UNIT}"]) + TEMP_UNIT.upper(),
                    "Feels Like Temperature": str(
                        data["forecast"]["forecastday"][i]["hour"][j][f"feelslike_{TEMP_UNIT}"]) + TEMP_UNIT.upper(),
                    "Climate Condition": data["forecast"]["forecastday"][i]["hour"][j]["condition"]["text"],
                    "Wind Speed": str(data["forecast"]["forecastday"][i]["hour"][j][f"wind_{SPD_UNIT}"]) + SPD_UNIT,
                    "Wind Degree": data["forecast"]["forecastday"][i]["hour"][j]["wind_degree"],
                    "Wind Direction": convert("dir", data["forecast"]["forecastday"][i]["hour"][j]["wind_dir"]),
                    "Pressure": str(data["forecast"]["forecastday"][i]["hour"][j]["pressure_mb"]) + f" millibars",
                    "Precipitation": str(
                        data["forecast"]["forecastday"][i]["hour"][j][f"precip_{PPT_UNIT}"]) + PPT_UNIT,
                    "Humidity": str(data["forecast"]["forecastday"][i]["hour"][j]["humidity"]) + "%",
                    "Visibility": str(
                        data["forecast"]["forecastday"][i]["hour"][j][f"vis_{convert('vis', SPD_UNIT)}"]) + convert(
                        "vis", SPD_UNIT),
                    "UV Index": data["forecast"]["forecastday"][i]["hour"][j]["uv"],
                })

            forecast_hour.append(hourly)

    print("\nFORECAST WEATHER REPORT")

    for i in range(len(forecast_day)):
        for key, value in forecast_day[i].items():
            print(f"{key} --> {value}")

        print()

        if is_hourly:
            for j in forecast_hour[i]:
                for key, value in j.items():
                    print(f"{key} --> {value}")
                print()
        print("-----------------------------------------------------------------------------\n")

    input("\nPress any key to continue...")


TEMP_UNIT = "c"
SPD_UNIT = "kph"
PPT_UNIT = "mm"
MAIN_MENU = "\n1. Launch App\n2. Settings\n3. Quit"
MAIN_MENU1 = "\n1. Current Weather\n2. Forecast Weather\n3. Back to Main Menu"
MAIN_MENU2 = "\nChange the units according to your usages\n\n1. Temperature (C/F)\n2. Speed(kmh/mph)\
    \n3. Precipitation(mm/in)\n4. Back to Main Menu"

while True:
    print(MAIN_MENU)
    chk = input("\nEnter your choice: ")

    if chk == "1":
        while True:
            print(MAIN_MENU1)
            chk1 = input("\nEnter your choice: ")

            if chk1 == "1":
                loc1 = input("\nEnter name of the location: ").title()
                data1 = api_request(loc1)

                try:
                    print(data1["error"]["message"], "Try again...")

                except KeyError:
                    if loc1 == data1["location"]["name"]:
                        display_current_report(data1)

                    if loc1 != data1["location"]["name"]:
                        print(f'Did you mean {data1["location"]["name"]}?')

                        while True:
                            chk11 = input("Enter yes or no: ").lower()

                            if chk11 == "yes":
                                display_current_report(data1)

                            elif chk11 == "no":
                                break

                            else:
                                print("Invalid input. Try again...")

            elif chk1 == "2":
                loc2 = input("\nEnter name of the location: ").title()
                while True:
                    try:
                        day = int(input("Enter number of days to forecast(1-14): "))
                        break
                    except ValueError:
                        print("Invalid number. Try again...")

                while True:
                    inp = input("Forecast display type(daily[D]/hourly [H]): ").upper()

                    if inp == "H":
                        flag = True
                        break

                    elif inp == "D":
                        flag = False
                        break

                    else:
                        print("Invalid input. Try again...")

                data2 = api_request(loc2, day)

                try:
                    print(data2["error"]["message"], " Try again...")

                except KeyError:
                    if loc2 == data2["location"]["name"]:
                        display_forecast_report(data2, day, flag)

                    else:
                        print(f'\nDid you mean {data2["location"]["name"]}?')

                        while True:
                            chk12 = input("Enter yes or no: ").lower()

                            if chk12 == "yes":
                                display_forecast_report(data2, day, flag)

                            elif chk12 == "no":
                                break

                            else:
                                print("Invalid input. Try again...")

            elif chk1 == "3":
                break

            else:
                print("Invalid input. Try again...")

    elif chk == "2":
        while True:
            print(MAIN_MENU2)
            chk2 = input("\nEnter your choice: ")

            if chk2 == "1":
                while True:
                    chk21 = input("\nChange the Temperature Unit(C/F): ").lower()

                    if chk21 in ("c", "f"):
                        TEMP_UNIT = chk21
                        print("Updated Successfully ")
                        break

                    else:
                        print("Invalid input. Try again...")

            elif chk2 == "2":
                while True:
                    chk22 = input("\nChange the Speed Unit(kph/mph): ").lower()

                    if chk22 in ("kph", "mph"):
                        SPD_UNIT = chk22
                        print("Updated Successfully ")
                        break

                    else:
                        print("Invalid input. Try again...")

            elif chk2 == "3":
                while True:
                    chk23 = input("\nChange the Precipitation Unit(mm/in): ").lower()

                    if chk23 in ("mm", "in"):
                        PPT_UNIT = chk23
                        print("Updated Successfully ")
                        break

                    else:
                        print("Invalid input. Try again...")

            elif chk2 == "4":
                break

            else:
                print("Invalid input. Try again...")

    elif chk == "3":
        print("\nThank you for using the app :)")
        break

    else:
        print("Invalid input. Try again...")
