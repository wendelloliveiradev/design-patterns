import { WeatherStationSubscribers, WeatherStationPublisher, WeatherState } from "./Interfaces";

class WeatherPublisher implements WeatherStationPublisher {
    private subscribers: WeatherStationSubscribers[] = [];
    private weather_state: WeatherState = {
        temperature: 0,
        humidity: 0,
        pressure: 0,
        wind_speed: 0,
        wind_direction: 0,
    };

    public addSubscriber(subscriber: WeatherStationSubscribers): void {
        this.subscribers.push(subscriber);
    }

    public removeSubscriber(observer: WeatherStationSubscribers): void {
        const index: number = this.subscribers.indexOf(observer);
        if (index > -1) {
            this.subscribers.splice(index, 1);
        }
    }

    public setWeatherState(weather_state: WeatherState): void {
        this.weather_state = weather_state;
        this.notifySubscribers();
    }

    public notifySubscribers(): void {
        for (const subscriber of this.subscribers) {
            subscriber.update(this.weather_state);
        }
    }
}

class WeatherSubscriber implements WeatherStationSubscribers {
    private weather_state: WeatherState = {} as WeatherState;
    private weather_sub_id: number = 0;

    constructor(id: number) {
        this.weather_sub_id = id;
    }

    public update(weather_state: WeatherState): void {
        this.weather_state = weather_state;

        console.log(`Weather subscriber ${this.weather_sub_id} has been updated.`);
        
        console.log(`
        Temperature: ${this.weather_state.temperature}.
        Humidity: ${this.weather_state.humidity}.
        Pressure: ${this.weather_state.pressure}.
        Wind speed: ${this.weather_state.wind_speed}.
        Wind direction: ${this.weather_state.wind_direction}.
        `);
    }
}

// Client code
const weatherStation = new WeatherPublisher();
const weather_subscriber_1 = new WeatherSubscriber(1);
const weather_subscriber_2 = new WeatherSubscriber(2);
const weather_subscriber_3 = new WeatherSubscriber(3);

weatherStation.addSubscriber(weather_subscriber_1);
weatherStation.addSubscriber(weather_subscriber_2);
weatherStation.addSubscriber(weather_subscriber_3);
weatherStation.setWeatherState({
    temperature: 20,
    humidity: 50,
    pressure: 1000,
    wind_speed: 10,
    wind_direction: 180,
});
weatherStation.setWeatherState({
    temperature: 25,
    humidity: 60,
    pressure: 1000,
    wind_speed: 10,
    wind_direction: 180,
});
weatherStation.removeSubscriber(weather_subscriber_2);
weatherStation.setWeatherState({
    temperature: 30,
    humidity: 70,
    pressure: 1000,
    wind_speed: 10,
    wind_direction: 180,
});
