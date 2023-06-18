// Each character attack strategy must implement this interface.
export interface AttackStrategy {
    attack(): void;
}