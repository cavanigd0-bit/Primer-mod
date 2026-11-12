#include <Geode/Geode.hpp>
#include <Geode/ui/LazySprite.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto sprite = LazySprite::create(CCSize{64.f, 64.f});
        sprite->setLoadCallback([sprite](Result<> result) {
            if (result) {
                log::info("Sprite loaded successfully!");
            } else {
                log::error("Sprite failed to load, setting fallback: {}", result.unwrapErr());
                sprite->initWithSpriteFrameName("globed-logo.png"_spr);
            }
        });
        sprite->loadFromUrl("https://globed.dev/logo.png");
        this->addChild(sprite);

        return true;
    }
};
