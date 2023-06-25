export type WeatherState = {
    temperature: number;
    humidity: number;
    pressure: number;
    wind_speed: number;
    wind_direction: number;
}

export interface WeatherStationSubscribers {
    update: (weather_state: WeatherState) => void;
}

export interface WeatherStationPublisher {
    addSubscriber: (observer: WeatherStationSubscribers) => void;
    removeSubscriber: (observer: WeatherStationSubscribers) => void; 
    setWeatherState: (weather_state: WeatherState) => void;
    notifySubscribers: () => void;
}