/**
  ******************************************************************************
  * This file is part of the TouchGFX 4.15.0 distribution.
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/**
 * @file touchgfx/events/ClickEvent.hpp
 *
 * Declares the touchgfx::ClickEvent class.
 */
#ifndef CLICKEVENT_HPP
#define CLICKEVENT_HPP

#include <touchgfx/Event.hpp>
#include <touchgfx/hal/Types.hpp>

namespace touchgfx
{
/**
 * A click event. The semantics of this event is slightly depending on hardware platform.
 * ClickEvents are generated by the HAL layer.
 *
 * @see Event
 */
class ClickEvent : public Event
{
public:
    /** Values that represent click event types. */
    typedef enum
    {
        PRESSED,  ///< An enum constant representing the pressed option
        RELEASED, ///< An enum constant representing the released option
        CANCEL    ///< An enum constant representing the cancel option
    } ClickEventType;

    /**
     * Initializes a new instance of the ClickEvent class.
     *
     * @param  type  The type of the click event.
     * @param  x     The x coordinate of the click event.
     * @param  y     The y coordinate of the click event.
     * @param  force (Optional) The force of the click. On touch displays this usually means how
     *               hard the user pressed on the display. On the windows platform, this
     *               will always be zero.
     */
    ClickEvent(ClickEventType type, int16_t x, int16_t y, int16_t force = 0)
        : _type(type), _x(x), _y(y), _force(force)
    {
    }

    /**
     * Gets the x coordinate of this event.
     *
     * @return The x coordinate of this event.
     */
    int16_t getX() const
    {
        return _x;
    }

    /**
     * Gets the y coordinate of this event.
     *
     * @return The y coordinate of this event.
     */
    int16_t getY() const
    {
        return _y;
    }

    /**
     * Sets the x coordinate of this event.
     *
     * @param  x The x coordinate of this event.
     */
    void setX(int16_t x)
    {
        _x = x;
    }

    /**
     * Sets the y coordinate of this event.
     *
     * @param  y The y coordinate of this event.
     */
    void setY(int16_t y)
    {
        _y = y;
    }

    /**
     * Sets the click type of this event.
     *
     * @param  type The type to set.
     */
    void setType(ClickEventType type)
    {
        _type = type;
    }

    /**
     * Gets the click type of this event.
     *
     * @return The click type of this event.
     */
    ClickEventType getType() const
    {
        return _type;
    }

    /**
     * Gets the force of the click. On touch displays this usually means how hard the user
     * pressed on the display. On the windows platform, this will always be zero.
     *
     * @return The force of the click.
     */
    int16_t getForce() const
    {
        return _force;
    }

    /**
     * Gets event type.
     *
     * @return The type of this event.
     */
    virtual Event::EventType getEventType()
    {
        return Event::EVENT_CLICK;
    }

private:
    ClickEventType _type;
    int16_t _x;
    int16_t _y;
    int16_t _force;
};

} // namespace touchgfx

#endif // CLICKEVENT_HPP
