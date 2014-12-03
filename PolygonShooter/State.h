/** @author Adam Olękiewicz
 * 
 * Top-down survival post-apocalyptic shooter
 * 
 * Abstract class State 
 * - wraps all game states and provides methods for main loop
 */

#ifndef STATE_H
#define	STATE_H

class State {
public:
	State();
	virtual ~State();
	
	virtual void handleInput() =0;	// .
	virtual void update() =0;		// .
	virtual void render() =0;		// Self-explanatory
	virtual void run() =0;			// Switches game to given state, should be redefined for each state
	
	enum Name {
		Game,
		Menu
	};
private:
};

#endif	/* STATE_H */

